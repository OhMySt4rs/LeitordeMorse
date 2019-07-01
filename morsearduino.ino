int tempoOn = 0, tempoOff = 0, firstOn = 0, firstOff = 1, tempo, leitura, count = 0, acabou = 0;
int morse[6];

void setup() {
   Serial.begin(9600);
   for (int i = 0; i < 6; i++) {
      morse[i] = -1;
   }
   pinMode(A0, INPUT);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   digitalWrite(2, LOW);
}
void converte () {
   int tot = 0;
   for (int i = 0; i < 6; i++) {
      if (morse[i] == -1)
         break;
      tot *= 10;
      tot += morse[i];
   }
   //Serial.println(tot);
   for (int i = 0; i < 6; i++)
      morse[i] = -1;
   switch (tot) { 
            case 12:
               Serial.print("A"); 
            break;
            case 2111:
               Serial.print("B"); 
            break;
            case 2121:
               Serial.print("C"); 
            break;
            case 211:
               Serial.print("D"); 
            break;
            case 1:
               Serial.print("E"); 
            break;
            case 1121:
               Serial.print("F"); 
            break;
            case 221:
               Serial.print("G"); 
            break;
            case 1111:
               Serial.print("H");
            break;
            case 11:
               Serial.print("I"); 
            break;
            case 1222:
               Serial.print("J"); 
            break;
            case 212:
               Serial.print("K"); 
            break;
            case 1211:
               Serial.print("L"); 
            break;
            case 22:
               Serial.print("M"); 
            break;
            case 21:
               Serial.print("N"); 
            break;
            case 222:
               Serial.print("O"); 
            break;
            case 1221:
               Serial.print("P"); 
            break;
            case 2212:
               Serial.print("Q"); 
            break;
            case 121:
               Serial.print("R"); 
            break;
            case 111:
               Serial.print("S"); 
            break;
            case 2:
               Serial.print("T"); 
            break;
            case 112:
               Serial.print("U"); 
            break;
            case 1112:
               Serial.print("V"); 
            break;
            case 122:
               Serial.print("W"); 
            break;
            case 2112:
               Serial.print("X"); 
            break;
            case 2122:
               Serial.print("Y"); 
            break;
            case 2211:
               Serial.print("Z"); 
            break;
            case 121212:
               Serial.print(" "); // ponto como espaço
            break;
   }
}
void loop () {
   leitura = analogRead(A0);
   if (leitura >= 500) {
      digitalWrite(2, HIGH);
   } 
   else {
      digitalWrite(2, LOW);     
   }
   if (leitura >= 500) { 
      if (firstOn == 0) {
         tempo = millis();
         firstOn = 1;
         firstOff = 0;
         tempoOff = 0;
         acabou = 0;
      }
      tempoOn = millis() - tempo;
      //Serial.println(tempoOn);
   }
   else {
      if (firstOff == 0) {
         tempo = millis();
         firstOff = 1;
         firstOn = 0;
         //Serial.println(count);
         if (tempoOn >= 0 && tempoOn < 400) {
            //Serial.print("ponto\n");
            morse[count] = 1;
            count++;
         }
         else { 
            //Serial.print("traco\n");
            morse[count] = 2;
            count++;
         }
         tempoOn = 0;
      }
      tempoOff = millis() - tempo;
      if (tempoOff > 1200 && acabou == 0) {
         //Serial.print("espaco\n");
         converte ();
         acabou = 1;
         count = 0;
      } 
      //Serial.println(tempoOff);
   }
}

