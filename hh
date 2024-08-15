basic-----------------------------
hostname R1
line console 0
password 1234
login
exit
enable secret cisco
ip domain-name nst21022.com
username root secret cisco
crypto key generate rsa

How many bits in the modulus [512]: 512


line vty 0 15
transport input ssh
login local
exec-timeout 4

service password-encryption

int g0/0/0	
ip add 192.168.1.1 255.255.255.0
no sh

dhcp----------------------------------
ip dhcp excluded-address 192.168.10.1 192.168.10.10
ip dhcp excluded-address 192.168.10.2 192.168.10.20
ip dhcp pool NET
network 192.168.10.0 255.255.255.0
default-router 192.168.1.1
dns-server 192.168.100.2
exit


vlan------------------------------------

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

interface range g0/1
switchport mode trunk



R1
int g0/0/0.10
encapsulation dot1Q 10
ip add 192.168.1.1 255.255.255.0

int g0/0/0.20
encapsulation dot1Q 20
ip add 192.168.1.2 255.255.255.0
exit
interface s0/1/0
ip add 192.168.1.3 255.255.255.0.

int g0/0/0.10
ip hlper-address 192.168.10.1


ospf-----------------------------
router ospf 1
router-id 1.1.1.1
network 10.1.1.0  0.0.0.255 area 0
network 10.1.2.0  0.0.0.255 area 0
passive-interface g0/0/0
passive-interface g0/0/1


ipv6-------------------------
ipv6 unicast-routing 
int g0/1
ipv6 address 2001:db8:cafe:a::1/64
no sh




standard static rout-------------------------------------
--------------R1
enable
conf t
hostname R1

interface gi0/0/1
ip address 192.168.1.1 255.255.255.0
ipv6 address 2008:db8:cafe:a::1/64
ipv6 address fe80::1 link-local
no shut
exit

interface gi0/0/0
ip address 192.168.2.1 255.255.255.0
ipv6 address 2008:db8:cafe:b::1/64
ipv6 address fe80::1 link-local
no shut
exit



interface se0/1/0
clock rate 6400
ip address 192.168.10.1 255.255.255.252
ipv6 address 2008:db8:abcd:a::1/64
ipv6 address fe80::1 link-local
no shut
exit

ipv6 unicast-routing

ip route 192.168.3.0 255.255.255.0 192.168.10.2
ip route 192.168.4.0 255.255.255.0 192.168.10.2

ipv6 route 2008:db8:cafe:c::/64 2008:db8:abcd:a::2
ipv6 route 2008:db8:cafe:d::/64 2008:db8:abcd:a::2

