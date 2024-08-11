Router(config)#hostname R1
R1(config)#line console 0
R1(config-line)#password 1234
R1(config-line)#login
R1(config-line)#exit
R1(config)#enable secret cisco
R1(config)#ip domain-name nst21022.com
R1(config)#username root secret cisco
R1(config)#crypto key generate rsa
The name for the keys will be: R1.nst21022.com
Choose the size of the key modulus in the range of 360 to 4096 for your
  General Purpose Keys. Choosing a key modulus greater than 512 may take
  a few minutes.

How many bits in the modulus [512]: 512
% Generating 512 bit RSA keys, keys will be non-exportable...[OK]

R1(config)#line vty 0 15
*Mar 1 0:8:18.441: RSA key size needs to be at least 768 bits for ssh version 2
*Mar 1 0:8:18.444: %SSH-5-ENABLED: SSH 1.5 has been enabled
R1(config-line)#transport input ssh
R1(config-line)#login local
R1(config-line)#exec-timeout 4
R1(config)#service password-encryption
R1(config)#banner motd #ghghjhj#
R1(config)#int g0/0/0
	
R1(config-if)#ip add 192.168.1.1 255.255.255.0
R1(config-if)#no sh

R1(config-if)# 

vlan

Switch(config)#vlan 10
Switch(config-vlan)#name hr
Switch(config-vlan)#vlan 20
Switch(config-vlan)#name manegment
Switch(config-vlan)#exit
Switch(config)#int range f0/1-8
Switch(config-if-range)#switchport mode access
Switch(config-if-range)#switchport access vlan 10
Switch(config-if-range)#int range f0/9-16
Switch(config-if-range)#switchport mode access
Switch(config-if-range)#switchport access vlan 20
Switch(config)#int range g0/1
Switch(config-if-range)#switchport mode trunk


R1(config)#int g0/0/0.10
R1(config-subif)#
%LINK-5-CHANGED: Interface GigabitEthernet0/0/0.10, changed state to up

R1(config-subif)#encapsulation dot1Q 10
R1(config-subif)#ip add 192.168.1.1 255.255.255.0
% 192.168.1.0 overlaps with GigabitEthernet0/0/0
R1(config-subif)#int g0/0/0.20
R1(config-subif)#
%LINK-5-CHANGED: Interface GigabitEthernet0/0/0.20, changed state to up

R1(config-subif)#encapsulation dot1Q 20
R1(config-subif)#ip add 192.168.1.2 255.255.255.0
% 192.168.1.0 overlaps with GigabitEthernet0/0/0
R1(config-subif)#exit
R1(config)#interface s0/1/0
R1(config)#ip add 192.168.1.3 255.255.255.0.

R1(config)#ip dhcp pool NET-10
R1(dhcp-config)#no ip dhcp pool NET-10
R1(config)#ip dhcp excluded-address 192.168.1.1 192.168.1.10
R1(config)#ip dhcp excluded-address 192.168.2.1 192.168.2.10
R1(config)#ip dhcp pool NET-10
R1(dhcp-config)#network 192.168.1.0 255.255.255.0
R1(dhcp-config)#default-router 192.168.1.1
R1(dhcp-config)#dns-server 192.168.100.2
R1(dhcp-config)#
R1(dhcp-config)#ip dhcp pool NET-20
R1(dhcp-config)#default-router 192.168.2.1
R1(dhcp-config)#default-router 192.168.2.1
R1(dhcp-config)#dns-server 192.168.100.2
Router(config)#int g0/0/0.20
Router(config-subif)#ip helper-address 192.168.1.3
Router(config-subif)#int g0/0/0.10
Router(config-subif)#ip helper-address 192.168.1.3
Router(config-subif)#no sh

