#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
    ofstream out("rez.txt");
       struct komanda{
        string vardas;
        float laikas;
        int metai;
      };
      void kiekisElementu(int &kiekis, const char byla[]);
      void skaitom(komanda Struktura[], int kiekis, const char byla[]);
      void rasom(komanda Struktura[], int kiekis, string txt);
      void kuriam(komanda Struktura[], int kiekis,komanda BendriDuomenys[], int nuoKiek);


      int main()
      {
        int kiek1, kiek2;
        const char duomenys1[] = "kom1.txt";
        const char duomenys2[] = "kom2.txt";
        kiekisElementu(kiek1, duomenys1);
        kiekisElementu(kiek2, duomenys2);
        komanda begikai1[kiek1], begikai2[kiek2], bendraKomanda[kiek1+kiek2];
        int kiekisViso;
        kiekisViso=kiek1+kiek2;
        skaitom(begikai1, kiek1, duomenys1);
        skaitom(begikai2, kiek2, duomenys2);
        rasom(begikai1, kiek1, "Pirma komanda \n");
        rasom(begikai2, kiek2, "Antra komanda \n");
        kuriam(begikai1, kiek1, bendraKomanda, 0);
        kuriam(begikai2, kiek2, bendraKomanda, kiek1);
        rasom(bendraKomanda, kiekisViso, "Bendra Komanda \n");

  out.close();
  return 0;
  }

 void kiekisElementu(int &kiekis, const char byla[]){
     ifstream in(byla);
     komanda LaikStruktura[1];
     kiekis=0;
     while(!in.eof()){
        in>>LaikStruktura[0].vardas>>LaikStruktura[0].laikas>>LaikStruktura[0].metai;
        kiekis++;
     }
     in.seekg(0);
     in.close();


 }
//=======================skatom=================================
  void skaitom(komanda Struktura[], int kiekis, const char byla[]){
      ifstream in(byla);
      for(int i=0; i<kiekis; i++){
        in>>Struktura[i].vardas>>Struktura[i].laikas>>Struktura[i].metai;

      }
      in.close();
  }
//========================rasom=======================================
    void rasom(komanda Struktura[], int kiekis,string txt){
      out<<txt;
      for(int i=0; i<kiekis; i++){
        out<<setw(20)<<left<<Struktura[i].vardas<<setw(4)<<right<<Struktura[i].laikas
        <<setw(4)<<right<<Struktura[i].metai;


      out<<endl;}
  }

//--------------------------kuriam-------------------------------

void kuriam(komanda Struktura[], int kiekis,komanda BendriDuomenys[], int nuoKiek){

        for(int i=0; i<kiekis; i++){
            BendriDuomenys[nuoKiek].vardas=Struktura[i].vardas;
            BendriDuomenys[nuoKiek].laikas=Struktura[i].laikas;
            BendriDuomenys[nuoKiek].metai=Struktura[i].metai;
            nuoKiek++;
}


}



