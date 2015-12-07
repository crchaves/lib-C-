

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
char *data;
float m,n;
char str [80];
 int d;
  FILE * pFile;

 time_t tiempo ;
        struct tm *tlocal ;
        char output[128];
        

tiempo = time(NULL);
tlocal = localtime(&tiempo);
strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);


  pFile = fopen ("/tmp/1.txt","r");
if (pFile!=NULL)
  {
  fscanf (pFile, "%d", &d);
  fclose (pFile);
}
else d=0;
n=d; 
n=n/10;

system("cat /sys/bus/iio/devices/iio\\:device0/in_voltage1_raw > /tmp/1.txt &");
   
data = getenv("QUERY_STRING");
if(data == NULL)
  printf("<P>Error! Error in passing data from form to script.");
else if(sscanf(data,"consigna=%f",&m)!=1)
{
printf("<html>");
printf("<head>");
printf("</head>");
printf("<body>\n");
  printf("<P>Error! parametros mal en la llamada.");

printf("</body>");
printf("</html>");
}
else
{



system("echo none > /sys/class/leds/green/trigger");



printf("<html>");
printf("<head>");
printf("<TITLE>prueba</TITLE>\n");
printf("<H3>prueba</H3>\n");
printf("<meta content=\"5\" URL=\"/cgi-bin/cgi?consigna=20.5\" http-equiv=\"REFRESH\" > </meta>");
printf("</head>");
printf("<body>\n");

if(n>m){system("echo 1 > /sys/class/leds/green/brightness");  printf("<p>SALIDA apagada");  }
 else {system("echo 0 > /sys/class/leds/green/brightness");  printf("<p><b>SALIDA ACTIVADA</b>");} 


printf("<p><p>FECHA SISTEMA =  %s\n",output);

  //printf("<P>salida %02.1f entrada es %02.1f.",m,n);
printf("<form>\n");
printf("Temperatura deseada: <input value=\"%02.1f\" type=\"number\" min=\"15\" max=\"35\" name=\"consigna\"><br>\n", m);
printf("<P>\n");
printf("Temperatura habitacion: %02.1f <br>\n",n);

printf("</form> \n");

printf("</body>");
printf("</html>");
}
return 0;
}


