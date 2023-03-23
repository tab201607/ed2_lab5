char state1 = 0, nextstate1 = 0; //control de estados jugador 1
char state2 = 0, nextstate2 = 0; //control de estados jugador 2
int gamestate = 0; //0 = todavia no ha empezado, 1 = en juego, 2 = jugador 1 gano, 3 = jugador 2 gano

//byte A, B, C, D, E, F, G, H;

int greenlightsout = 0;


void setup() {
  Serial.begin(115200);
  
  //Control semaforo
  pinMode(30, OUTPUT); //LED Rojo RGB
  pinMode(39, OUTPUT); //LED Verde RGB
  pinMode(40, OUTPUT); //LED Azul RGB

  //Control pin inicio
  interrupts();
 pinMode(31, INPUT_PULLUP);//pin PB2 como input y interrupt
  attachInterrupt(digitalPinToInterrupt(31), semaforo, RISING);


  //primer set  de pines para contador de decada || jugador 1
  pinMode(19, OUTPUT); //A
  pinMode(38, OUTPUT); //B
  pinMode(37, OUTPUT); //C
  pinMode(36, OUTPUT); //D
  pinMode(35, OUTPUT); //E
  pinMode(14, OUTPUT); //F
  pinMode(13, OUTPUT); //G 
  pinMode(32, OUTPUT); //H
  pinMode(11, INPUT_PULLUP); //input

  char state1 = 0;
 

  attachInterrupt(digitalPinToInterrupt(11), counter1, RISING); //jugador 1

 //segundo set  de pines para contador de decada || jugador 2
  pinMode(3, OUTPUT); //A
  pinMode(4, OUTPUT); //B
  pinMode(5, OUTPUT); //C
  pinMode(6, OUTPUT); //D
  pinMode(7, OUTPUT); //E
  pinMode(8, OUTPUT); //F
  pinMode(9, OUTPUT); //G 
  pinMode(10, OUTPUT); //H
  pinMode(2, INPUT_PULLUP); //input

  char state2 = 0;

  attachInterrupt(digitalPinToInterrupt(2), counter2, RISING); //jugador 2

  gamestate = 0;


  digitalWrite(40, LOW); //azul en bajo
}

void loop() {
  // put your main code here, to run repeatedly: 
 while(1) {
  if (gamestate == 2) {
    digitalWrite(40, HIGH);//poner luz azul en alto si jugador1 gana 
    digitalWrite(39, LOW); 
  }
  else if (gamestate == 3) {
    digitalWrite(39, HIGH);  //poner luz verde en alto si jugador2 gana
  }
  else digitalWrite(40, LOW);
 Serial.print(gamestate); 

//sistema para deactivar verde de semaforo despues de un tiempo sin utilizar un delay
 greenlightsout++;
 if (greenlightsout == 10000) digitalWrite(39, LOW);

 //controlar luces de ambos jugadores
 lights1(); 
 lights2();
}

}

void semaforo() {
  gamestate = 0;
  digitalWrite(40, LOW); //Azul en bajo
  digitalWrite(30, HIGH); //Rojo en alto
  digitalWrite(39, LOW);//Verde en alto
  delay(2000);
  digitalWrite(39, HIGH); //Verde + Rojo = amarillo
  delay(2000);
  digitalWrite(30, LOW); //Solo verde
  state1 = 0;
  state2 = 0;
  gamestate = 1;
  greenlightsout = 0;
}


//counter para jugador 1
void counter1() {
  Serial.println("go1!");
  
  if (gamestate == 1) state1 = nextstate1;




  
  delay(10);

  
  
}

//control del luces jugador 1
void lights1() { 
    byte A = 19; //A
byte  B = 38; //B
byte  C = 37; //C
byte  D = 36; //D
byte  E = 35; //E
byte  F = 14; //F
byte  G = 13; //G 
byte  H = 32; //H

//control de luces    
    switch (state1) {
      
    case 0:
     digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate1 = 1;
    break;
    case 1:
     digitalWrite(A, HIGH);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate1 = 2;
    break;
    case 2:
    digitalWrite(A, LOW);
     digitalWrite(B, HIGH);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate1 = 3;
    break;
    case 3:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, HIGH);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate1 = 4;
    break;
    case 4:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, HIGH);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate1 = 5;
    break;
    case 5:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, HIGH);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate1 = 6;
    break;
    case 6:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, HIGH);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate1 = 7;
    break;
    case 7:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, HIGH);
     digitalWrite(H, LOW);
     nextstate1 = 8;
    break;
    case 8:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, HIGH);
     nextstate1 = 9;
     break;
     case 9:
    digitalWrite(A, HIGH);
     digitalWrite(B, HIGH);
     digitalWrite(C, HIGH);
     digitalWrite(D, HIGH);
     digitalWrite(E, HIGH);
     digitalWrite(F, HIGH);
     digitalWrite(G, HIGH);
     digitalWrite(H, HIGH);
     gamestate = 2; //pone al juego en modo de jugador 1 gano 
     nextstate1 = 9;
     break;
     default:
     digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate1 = 0;
     break;}
}


//counter para jugador 2
void counter2() {
  Serial.println("go2!");
  
  if (gamestate == 1) state2 = nextstate2; //cambiar solo si el juego sigue
  
  delay(10);
}

//control del luces jugador 2

void lights2() {
  //selecciones de pines
  byte A = 3; //A
byte  B = 4; //B
byte  C = 5; //C
byte  D = 6; //D
byte  E = 7; //E
byte  F = 8; //F
byte  G = 9; //G 
byte  H = 10; //H

   
    switch (state2) {
      
    case 0:
     digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate2 = 1;
    break;
    case 1:
     digitalWrite(A, HIGH);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate2 = 2;
    break;
    case 2:
    digitalWrite(A, LOW);
     digitalWrite(B, HIGH);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate2 = 3;
    break;
    case 3:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, HIGH);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate2 = 4;
    break;
    case 4:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, HIGH);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate2 = 5;
    break;
    case 5:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, HIGH);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate2 = 6;
    break;
    case 6:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, HIGH);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate2 = 7;
    break;
    case 7:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, HIGH);
     digitalWrite(H, LOW);
     nextstate2 = 8;
    break;
    case 8:
    digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, HIGH);
     nextstate2 = 9;
     break;
     case 9:
    digitalWrite(A, HIGH);
     digitalWrite(B, HIGH);
     digitalWrite(C, HIGH);
     digitalWrite(D, HIGH);
     digitalWrite(E, HIGH);
     digitalWrite(F, HIGH);
     digitalWrite(G, HIGH);
     digitalWrite(H, HIGH);
     gamestate = 3; //pone al juego en modo de jugador 2 gano
     nextstate2 = 9;
     break;
     default:
     digitalWrite(A, LOW);
     digitalWrite(B, LOW);
     digitalWrite(C, LOW);
     digitalWrite(D, LOW);
     digitalWrite(E, LOW);
     digitalWrite(F, LOW);
     digitalWrite(G, LOW);
     digitalWrite(H, LOW);
     nextstate2 = 0;
     break;}
}
