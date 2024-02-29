#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//variable declaration
int ch;
char cmd[100],out[500];//array datastructure is used to store output of the commands!
char resp;
void protocol_statistics();
void rt_info();
void tcp_socket();
void udp_socket();
void ic_firefox();
void listen_estab();
void respond();

void protocol_statistics()
{
strcpy(cmd, "netstat -s");
system(cmd);
strcpy(out,"netstat -s >> out.txt");
system(out);
}

void rt_info()
{
strcpy(cmd, "netstat -r");
system(cmd);
strcpy(out,"netstat -r >> out.txt");
system(out);
}

void tcp_socket()
{
strcpy(cmd, "netstat -tn");
system(cmd);
strcpy(out,"netstat -tn >> out.txt");
system(out);
}

void udp_socket()
{
strcpy(cmd, "netstat -un");
system(cmd);
strcpy(out,"netstat -tn >> out.txt");
system(out);
}


void ic_firefox()
{
strcpy(cmd, "netstat -tanp | grep -i Firefox");
system(cmd);
strcpy(out,"netstat -tanp | grep -i Firefox >> out.txt");
system(out);
}

void listen_estab()
{
strcpy(cmd, "netstat -tanp | grep -i LISTEN");
printf("LISTEN STATE- ");
system(cmd);
strcpy(out,"netstat -tanp | grep -i LISTEN >> out.txt");
system(out);

strcpy(cmd, "netstat -tanp | grep -i ESTABLISHED");
printf("ESTABLISHED STATE - ");
system(cmd);
strcpy(out,"netstat -tanp | grep -i ESTABLISHED >> out.txt");
system(out);

}



//Menu for the program
void menu()
{
printf("\n*********************************************************************************\n");
printf("                                   MENU                                          \n");
printf("\n*********************************************************************************\n");
printf("Select an option from the given choices : \n");
printf("\n 1. Protocol Statistics \n 2. Routing Table Info \n 3. Active TCP Socket Connections \n 4. Active UDP Socket Connections \n 5.All Internet connections which are using Firefox \n 6. All Internet connections where the state is LISTEN / ESTABLISHED for UDP / TCP" );

printf("\n 7. Exit \n");
printf("*********************************************************************************\n");
printf("Enter the option u want :");
scanf("%d", &ch);
switch(ch)
{
case 1:

printf("Protocol statistics details for your device - \n");
printf("\n*********************************************************************************\n");
protocol_statistics();
printf("\n*********************************************************************************\n");
respond();
break;

case 2:
printf("Routing table information for your device - \n");
printf("\n*********************************************************************************\n");
rt_info();
printf("\n*********************************************************************************\n");
respond();
break;

case 3:
printf("Active TCP Socket connections on your device - ");
printf("\n*********************************************************************************\n");
tcp_socket();
printf("\n*********************************************************************************\n");
respond();
break;

case 4:
printf("Active UDP Socket connections on your device - ");
printf("\n*********************************************************************************\n");
udp_socket();
printf("\n*********************************************************************************\n");
respond();
break;


case 5:
printf("Connections that are using browser on your device - ");
printf("\n*********************************************************************************\n");
ic_firefox();
printf("\n*********************************************************************************\n");
respond();
break;

case 6:
printf("State for all Internet connections for your device - ");
printf("\n*********************************************************************************\n");
listen_estab();
printf("\n*********************************************************************************\n");
respond();
break;

case 7:
exit(0);
break;

default:
printf("\n*********************************************************************************\n");
printf("\nInvalid\n");
break;

}
}

void respond(){
printf("Do you want to use other options(y/n)? \n");
scanf("%s",&resp);
if(resp=='y' || resp=='Y')
menu();
else if(resp=='n' || resp=='N')
exit(0);
else
printf("\nInvalid response!\n");

}


//main function

int main() {
printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
printf("||				PORT SCANNER				      ||\n");
printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
sleep(1);
menu();
return 0;
}