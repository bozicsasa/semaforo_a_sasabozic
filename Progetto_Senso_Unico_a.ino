//Creato da Bozic Sasa e Bragagnolo Riccardo.
int r1 = 9;
int g1 = 10;
int v1 = 11;
int r2 = 5;
int g2 = 3;
int v2 = 4;
int nLampeggi = 0;
int durataVerde = 0;
int durataGiallo = 0;
int durataRosso = durataVerde + durataGiallo;
void setup() {
  pinMode (9, OUTPUT); //rosso austriaco
  pinMode (10, OUTPUT); //giallo austriaco
  pinMode (11, OUTPUT); //verde austriaco
  pinMode (2, OUTPUT); //rosso austriaco 2
  pinMode (3, OUTPUT); //giallo austriaco 2
  pinMode (4, OUTPUT); //verde austriaco 2
  Serial.begin(9600);
  nLampeggi = seriale("Quanti lampeggi deve fare il verde?", nLampeggi);
  durataVerde = seriale("Quanto deve durare il verde?", durataVerde);
  durataGiallo = seriale("Quanto deve durare il giallo?", durataGiallo);
}

void blinks(int verde) {
  for (int a=0; a<nLampeggi; a++){
    digitalWrite (verde, HIGH);
    delay (200);
    digitalWrite (verde, LOW);
    delay (200);
    }
  }

void rossoVerde() {
  digitalWrite (r1, HIGH);
  digitalWrite (g1, LOW);
  digitalWrite (v1, LOW);
  delay (durataRosso);

  digitalWrite (v2, HIGH);
  digitalWrite (g2, LOW);
  digitalWrite (r2, LOW);
  delay (durataVerde);
  }

  void gialloRosso(){
  digitalWrite (r1, HIGH);
  digitalWrite (g1, HIGH);
  digitalWrite (v1, LOW);
  delay (durataGiallo);
  digitalWrite (v2, LOW);                                                                                
  digitalWrite (g2, HIGH);
  digitalWrite (r2, LOW);
  delay (durataGiallo);
  }

  void verdeRosso(){
  digitalWrite (r1, LOW);
  digitalWrite (g1, LOW);
  digitalWrite (v1, HIGH);
  delay (durataVerde);
  digitalWrite (v2, LOW);
  digitalWrite (g2, LOW);
  digitalWrite (r2, HIGH);
  delay (durataRosso);
  }
  void verde1Lampeggio(){
   blinks(v1);
  }
  void verde2Lampeggio(){
    blinks(v2);
  }
  
int seriale(String s, int i){
  Serial.println(s);
  while (Serial.available()==0){};
  i = Serial.readString().toInt();
  return i;
  }

void loop() {
  verde2Lampeggio();
  rossoVerde();
  gialloRosso();
  verdeRosso();
  verde1Lampeggio();
  
  


  
}

