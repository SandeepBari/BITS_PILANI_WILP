
const int trigPin_Rear= 9;
const int echoPin_Rear= 8;
const int trigPin_Front= 10;
const int echoPin_Front= 11;
const int red_LED= 13;
const int green_LED= 7;
const int buzzer= 12;

int distance_Front= 0;
int distance_Rear= 0;

void setup ()
{
 pinMode(trigPin_Front, OUTPUT);
 pinMode(echoPin_Front, INPUT);
 pinMode(trigPin_Rear, OUTPUT);
 pinMode(echoPin_Rear, INPUT);
 pinMode(red_LED, OUTPUT);
 pinMode(green_LED, OUTPUT);
 pinMode(buzzer, OUTPUT);
 
 Serial.begin(9600);
}

void loop ()
{
 digitalWrite(trigPin_Front, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin_Front, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin_Front, LOW);
 
 distance_Front= (((pulseIn(echoPin_Front, HIGH )) * 0.034) / 2);
 Serial.print("SandeepBari_2021HT65677_FRONT_DISTANCE: ");
 Serial.print(distance_Front);
 Serial.print(" cm");
 Serial.println();
 
 digitalWrite(trigPin_Rear, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin_Rear, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin_Rear, LOW);
 
 distance_Rear= (((pulseIn(echoPin_Rear, HIGH )) * 0.034) / 2);
 Serial.print("SandeepBari_2021HT65677_REAR_DISTANCE: ");
 Serial.print(distance_Rear);
 Serial.print(" cm");
 Serial.println();
 
 delay(500);

 if ( distance_Front > 50 && distance_Rear > 50 )
 {
  digitalWrite(red_LED, LOW );
  digitalWrite(buzzer, LOW );
  digitalWrite(green_LED, HIGH );  
 }

 else if ( distance_Front < 50 || distance_Rear < 50 )
 {
  digitalWrite(red_LED, HIGH );
  digitalWrite(buzzer, HIGH );
  digitalWrite(green_LED, LOW );  
 }

 else
 {
  digitalWrite(red_LED, LOW );
  digitalWrite(buzzer, LOW );
  digitalWrite(green_LED, HIGH );
 }
 
}
