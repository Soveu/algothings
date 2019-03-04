#include<cstdio>

enum Pieniadz{
  GR1,
  GR2,
  GR5,
  GR10,
  GR20,
  GR50,
  ZL1,
  ZL2,
  ZL5,
  ZL10,
  ZL20,
  ZL50,
  ZL100,
  ZL200,
  ZL500,
};

int main() {
  int wartosci[] = {1,2,5,10,20,50,1,2,5,10,20,50,100,200,500};
  char buf[16]{0};

  int zloty=0, groszy=0;

  scanf("%15s", buf);
  
  for(int i=Pieniadz::GR1; i<=Pieniadz::GR50; ++i){
    groszy += (buf[i] - 0x30) * wartosci[i];
  }

  for(int i=Pieniadz::ZL1; i<=Pieniadz::ZL500; ++i){
    zloty += (buf[i] - 0x30) * wartosci[i];
  }

  zloty += (groszy / 100);
  groszy %= 100;

  printf("%d.%02d\n", zloty, groszy);

  return 0;
}
  


