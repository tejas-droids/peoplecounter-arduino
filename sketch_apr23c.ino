const int trig=4;
const int echo=5;
int previous=0;
int current=0;
int counter=1;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  double duration=pulseIn(echo,HIGH);
  int distance=0.034*duration/2;
  Serial.println(distance);

  if(distance<10)
  {
    current= HIGH;
  }
  else
  {
    current=LOW;
  }
  if(current==HIGH&&current!=previous)
  {
    counter++;
  }
  delay(50);
  previous=current;
  if(counter%2==0)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
}
  
 
