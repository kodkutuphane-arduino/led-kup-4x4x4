// 4x4x4 LED Küp için Arduino Kodu

int arti[4] = {A0, A1, A2, A3};        
int eksi[16] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A4, A5, 0, 1};  
int sure = 100;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(arti[i], OUTPUT);
    digitalWrite(arti[i], LOW);
  }
  for (int i = 0; i < 16; i++) {
    pinMode(eksi[i], OUTPUT);
    digitalWrite(eksi[i], HIGH);
  }
}

void tumLedleriYak(int katman) {
  digitalWrite(arti[katman], HIGH);
  for (int i = 0; i < 16; i++) {
    digitalWrite(eksi[i], LOW);
  }
  delay(sure);
  for (int i = 0; i < 16; i++) {
    digitalWrite(eksi[i], HIGH);
  }
  digitalWrite(arti[katman], LOW);
}

void tekTekYakSondur() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(arti[i], HIGH);
    for (int j = 0; j < 16; j++) {
      digitalWrite(eksi[j], LOW);
      delay(sure);
      digitalWrite(eksi[j], HIGH);
    }
    digitalWrite(arti[i], LOW);
  }
}

void tumKatmanlarYakSondur() {
  for (int i = 0; i < 4; i++) {
    tumLedleriYak(i);
  }
  delay(sure);
}

void yagmurEfekti() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(arti[j], HIGH);
      digitalWrite(eksi[i], LOW);
      delay(sure);
      digitalWrite(eksi[i], HIGH);
      digitalWrite(arti[j], LOW);
    }
  }
}

void spiralEfekti() {
  int spiralSira[16] = {0,1,2,3,7,11,15,14,13,12,8,4,5,6,10,9};
  for(int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int i = 0; i < 16; i++) {
      digitalWrite(eksi[spiralSira[i]], LOW);
      delay(sure);
      digitalWrite(eksi[spiralSira[i]], HIGH);
    }
    digitalWrite(arti[z], LOW);
  }
}

void dalgaEfekti() {
  for(int x = 0; x < 4; x++) {
    for (int z = 0; z < 4; z++) {
      digitalWrite(arti[z], HIGH);
      for (int y = 0; y < 4; y++) {
        int index = x + y*4;
        digitalWrite(eksi[index], LOW);
      }
      delay(sure);
      for (int y = 0; y < 4; y++) {
        int index = x + y*4;
        digitalWrite(eksi[index], HIGH);
      }
      digitalWrite(arti[z], LOW);
    }
  }
}

void yilanEfekti() {
  for (int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int i = 0; i < 16; i++) {
      digitalWrite(eksi[i], LOW);
      delay(sure / 2);
      digitalWrite(eksi[i], HIGH);
    }
    digitalWrite(arti[z], LOW);
  }
}

void kalpSekli() {
  int kalp[4][4] = {
    {0,1,1,0},
    {1,1,1,1},
    {1,1,1,1},
    {0,1,1,0},
  };
  for(int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        int idx = y * 4 + x;
        if (kalp[y][x] == 1) {
          digitalWrite(eksi[idx], LOW);
        }
      }
    }
    delay(sure * 2);
    for (int i = 0; i < 16; i++) digitalWrite(eksi[i], HIGH);
    digitalWrite(arti[z], LOW);
  }
}
// 2. Yükselme ve Alçalma Efekti (Katmanlarla nefes alma)
void yukselmeAlcalma() {
  // Katmanları sırayla açıp kapat
  for (int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int i = 0; i < 16; i++) digitalWrite(eksi[i], LOW);
    delay(sure);
    for (int i = 0; i < 16; i++) digitalWrite(eksi[i], HIGH);
    digitalWrite(arti[z], LOW);
  }
  for (int z = 3; z >= 0; z--) {
    digitalWrite(arti[z], HIGH);
    for (int i = 0; i < 16; i++) digitalWrite(eksi[i], LOW);
    delay(sure);
    for (int i = 0; i < 16; i++) digitalWrite(eksi[i], HIGH);
    digitalWrite(arti[z], LOW);
  }
}

// 3. Dönerek Yükselen Spiral
void donerekYukselenSpiral() {
  int spiralSira[16] = {0,1,2,3,7,11,15,14,13,12,8,4,5,6,10,9};
  for (int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int i = 0; i < 16; i++) {
      digitalWrite(eksi[spiralSira[i]], LOW);
      delay(sure);
      digitalWrite(eksi[spiralSira[i]], HIGH);
    }
    digitalWrite(arti[z], LOW);
  }
  // Sonra ters yönde spiral çıkar gibi gösterelim (üst katmana doğru)
  for (int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int i = 15; i >= 0; i--) {
      digitalWrite(eksi[spiralSira[i]], LOW);
      delay(sure);
      digitalWrite(eksi[spiralSira[i]], HIGH);
    }
    digitalWrite(arti[z], LOW);
  }
}

// 4. Ateşböceği Efekti (Random parlayan noktalar)
void atesbogegi() {
  for (int i = 0; i < 30; i++) {
    int rastgeleKatman = random(0, 4);
    int rastgeleLed = random(0, 16);
    digitalWrite(arti[rastgeleKatman], HIGH);
    digitalWrite(eksi[rastgeleLed], LOW);
    delay(sure / 2);
    digitalWrite(eksi[rastgeleLed], HIGH);
    digitalWrite(arti[rastgeleKatman], LOW);
    delay(sure / 2);
  }
}

// 5. Hedefe Atış Efekti (Ortaya doğru çaprazlar)
void hedefAtis() {
  // Çapraz sütunlar (X-Y düzleminde) 0-15 arasında çaprazlar:
  int caprazlar[8][4] = {
    {0, 5, 10, 15},  // Sol üst köşeden sağ alt köşeye çapraz
    {3, 6, 9, 12}    // Sağ üst köşeden sol alt köşeye çapraz
  };
  for (int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    // İlk çapraz
    for (int i = 0; i < 4; i++) digitalWrite(eksi[caprazlar[0][i]], LOW);
    delay(sure);
    for (int i = 0; i < 4; i++) digitalWrite(eksi[caprazlar[0][i]], HIGH);
    // İkinci çapraz
    for (int i = 0; i < 4; i++) digitalWrite(eksi[caprazlar[1][i]], LOW);
    delay(sure);
    for (int i = 0; i < 4; i++) digitalWrite(eksi[caprazlar[1][i]], HIGH);
    digitalWrite(arti[z], LOW);
  }
}

// 6. Zikzak Efekti
void zikzakEfekti() {
  // Zigzag yolu sütun indekslerinde, her katmanda farklı yolla:
  int zikzak[16] = {0,1,5,4,8,9,13,12,16,17,21,20,24,25,29,28};
  // Yukarıdaki değerler 16'yı aşıyor, sütun max 15, düzeltelim
  // 4x4 matris üzerinde zigzag örneği:
  int zigzagIndex[16] = {0,1,5,4,6,7,11,10,8,9,13,12,14,15,3,2};

  for (int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int i = 0; i < 16; i++) {
      digitalWrite(eksi[zigzagIndex[i]], LOW);
      delay(sure / 5);
      digitalWrite(eksi[zigzagIndex[i]], HIGH);
    }
    digitalWrite(arti[z], LOW);
  }
}

// 7. Katman Katman Dolma (Voxel Build-Up)
void katmanKatmanDolma() {
  for (int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int kat = 0; kat <= z; kat++) {
      for (int i = 0; i < 16; i++) {
        digitalWrite(eksi[i], LOW);
      }
      delay(sure);
      for (int i = 0; i < 16; i++) {
        digitalWrite(eksi[i], HIGH);
      }
    }
    digitalWrite(arti[z], LOW);
  }
}

// 8. Patlama Efekti (Explosion Burst)
void patlamaEfekti() {
  // Ortadaki dört sütunu (5,6,9,10) ve katmanları içe ve dışa yakalım
  int merkezLedler[4] = {5,6,9,10};
  // Patlama için önce tüm merkez yanar, sonra dışa yayılır

  // Tüm merkez yanar
  for (int z = 0; z < 4; z++) {
    digitalWrite(arti[z], HIGH);
    for (int i = 0; i < 4; i++) digitalWrite(eksi[merkezLedler[i]], LOW);
    delay(sure);
    digitalWrite(arti[z], LOW);
    for (int i = 0; i < 4; i++) digitalWrite(eksi[merkezLedler[i]], HIGH);
  }

  // Dışa doğru yayılma: Kenar sütunları ve tüm katmanlar
  int yayilma[4][16] = {
    {5,6,9,10},              // merkez
    {1,2,4,7,8,11,13,14},   // biraz dışa
    {0,3,12,15},            // kenarlar
    {}                      // tam dış (boş bırakıldı)
  };

  for (int i = 0; i < 3; i++) {
    for (int z = 0; z < 4; z++) {
      digitalWrite(arti[z], HIGH);
      for (int j = 0; j < 16; j++) digitalWrite(eksi[j], HIGH);
      for (int k = 0; k < 8; k++) {
        if (yayilma[i][k] >= 0) digitalWrite(eksi[yayilma[i][k]], LOW);
      }
      delay(sure);
      digitalWrite(arti[z], LOW);
    }
  }
}



void loop() {
  tekTekYakSondur();
  tumKatmanlarYakSondur();
  yagmurEfekti();
  spiralEfekti();
  dalgaEfekti();
  yilanEfekti();
  kalpSekli();
  yukselmeAlcalma();    // 2
  donerekYukselenSpiral(); // 3
  atesbogegi();         // 4
  hedefAtis();          // 5
  zikzakEfekti();       // 6
  katmanKatmanDolma();  // 7
  patlamaEfekti();      // 8
  delay(1000);
}
