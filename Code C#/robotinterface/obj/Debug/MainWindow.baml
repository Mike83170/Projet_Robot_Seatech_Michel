   M S B A M L   `   `   `  ����I  Erobotinterface, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null/clr-namespace:RobotinterfaceRobotinterface  5   	       Robotinterface.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   .localclr-namespace:Robotinterface     5   	     � Title$  
MainWindow��5   	   $	��450��6   $	��800��6)   .��5	      �  � RowDefinitions 5
   
   �� 5      $��30 �6   �� 5      �� 5      $��30 �6   �� 5      $��30 �6   �� 5      $��30 �6    � ColumnDefinitions 5   
   �� 5      $��30 �6   �� 5      �� 5      $��30 �6   �� 5      �� 5      $��30 �6   .+�5   
   �� -   5         ��Name$ envoi��5      $��Emission��6"   $��Stretch=�64   $��0q�6R   $��Stretch=�6]   ���	#FFDDDDDD���	#FF000000$��1��6�   $��1��6�   .��5      �� -   5         ��Name$	 env��5      $��Stretch=�6#   $��0q�6A    �� TextWrapping$
 Wrap=�6L   $��textBoxEmission��6`   ���	#FFDDDDDD$��Stretch=�6�    �� AcceptsReturn . 6�   5      �� 5   
   -   5        $ 	reception��5      $��	Reception��6&   $��Stretch=�69   $��0q�6W   $��Stretch=�6b   ���	#FFDDDDDD���	#FF000000$��3��6�   $��1��6�   .��5      �� -   5        $	 rec��5      $��Stretch=�6#   $��0q�6A   $
 Wrap=�6L   $��TextBoxReception��6`   $��Stretch=�6x   ���	#FFDDDDDD �� 
IsReadOnly . 6�   5      �� 5   
   -   5         ��Name$ buttonEnvoyer��5      $��Envoyer��6(   $��1��6:   $
��Left=�6J   $��0q�6e   $��3��6p   $	��100��6}   6�   �� 5   
   -   5        $ buttonClear��5      $��Clear��6&   $��1��66   $��Right=�6F   $��0q�6b   $��3��6m   $	��100��6z   6�   �� 5    
   -   5        $ 
buttonTest��5       $
��Test��6%   $��1��64   $��Center=�6D   $��0q�6a   $��3��6l   $	��100��6y   6�   5!      5"      