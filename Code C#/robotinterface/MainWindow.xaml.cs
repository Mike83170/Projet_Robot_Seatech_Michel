using ExtendedSerialPort;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace Robotinterface
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        ReliableSerialPort serialPort1;
        string receivedtext;
        DispatcherTimer timerAffichage;
        Robot robot = new Robot();
        Queue<byte> byteListReceived = new Queue<byte>();


        public MainWindow()
        {
            InitializeComponent();
            serialPort1 = new ReliableSerialPort("COM4", 115200, System.IO.Ports.Parity.None, 8, System.IO.Ports.StopBits.One);
            serialPort1.DataReceived += SerialPort1_DataReceived1;
            serialPort1.Open();
            timerAffichage = new DispatcherTimer();
            timerAffichage.Interval = new TimeSpan(0, 0, 0, 0, 100);
            timerAffichage.Tick += TimerAffichage_Tick;
            timerAffichage.Start();
        }

        private void SerialPort1_DataReceived1(object sender, ExtendedSerialPort.DataReceivedArgs e)
        {
            // receivedtext += Encoding.UTF8.GetString(e.Data, 0, e.Data.Length);
            foreach (byte c in e.Data)
            {
                byteListReceived.Enqueue(c);
            }
        }

        private void TimerAffichage_Tick(object sender, EventArgs e)
        {
            //rec.Text = receivedtext;

            while (byteListReceived.Count() > 0)
            {
                byte c = byteListReceived.Dequeue();
                rec.Text += "0x" + c.ToString("X2") + " ";
            }
        }

        bool toogle = true;


        private void buttonEnvoyer_Click(object sender, RoutedEventArgs e)
        {
            if (toogle == true)
            {
                buttonEnvoyer.Background = Brushes.RoyalBlue;
                toogle = false;
                SendMessage();
            }


            else if (toogle == false)
            {
                buttonEnvoyer.Background = Brushes.Beige;
                toogle = true;
                SendMessage();
            }
        }

        private void env_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                SendMessage();
            }
        }
        private void SendMessage()
        {
            byte[] buffer = Encoding.ASCII.GetBytes(env.Text);
            env.Text = "";
            serialPort1.Write(buffer, 0, buffer.Length);

            //serialPort1.WriteLine(env.Text);
            //env.Text = "";
        }

        private void buttonClear_Click(object sender, RoutedEventArgs e)
        {
            receivedtext = "" + "Toto";
            rec.Text = receivedtext;
        }

        private void buttonTest_Click(object sender, RoutedEventArgs e)
        {
            byte[] byteList = new byte[20];
            for (int i = 0; i < byteList.Length; i++)
            {
                byteList[i] = (byte)(2 * i);
            }
            serialPort1.Write(byteList, 0, byteList.Length);
        }
    }
}
