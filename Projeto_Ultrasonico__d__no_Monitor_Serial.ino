//Projeto de apresentação de distância (medida por um sensor ultrassônico HC-SR04) e apresentada no Monitor Serial.

#include <Ultrasonic.h> //Inclusão da bibilioteca do sensor ultrassônico (HC-SR04)

const int Echo = 31; //Pinagem do ECHO/Retorno do sensor
const int Trig = 30;//Pinagem do TRIG/Gatilho do sensor

Ultrasonic ultrasonic(Trig, Echo);//Função que recebe os parâmetros Trig e Echo

//Declaração de variáveis que serão manipuladas
int distancia; 
String result; 
unsigned char sinal; 

//Loading/priorizando a leitura  das funções principais 
void Distancia();
void hcsr04();

//Função de inicialização do sistema
void setup()
{
  Serial.begin (9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}

//Exibição da distância do Monitor Serial
void Distancia(void)
{
  if (Serial.available() > 0)
  {
    sinal = Serial.read();

    if (sinal == 'a')
    {
      hcsr04();
      Serial.print(result);
      Serial.print(" cm");
    }
  }
}

//Função de cálculo da distância == d = (T[tempo de resposta do sensor]*Vsom)/2
void hcsr04() {
  digitalWrite(Trig, 0);    
  delayMicroseconds(2);        
  digitalWrite(Trig, 1);   
  delayMicroseconds(10);        
  digitalWrite(Trig, 0);     
  distancia = (ultrasonic.Ranging(CM)); 
  result = String(distancia);     
  delay(500);                    
}



void loop()
{
  Distancia();
}
