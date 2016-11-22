#include<stdio.h>
typedef unsigned char byte;

int main(int argc,char* argv[]){
  //宣言と初期化
  byte buf[30000]={0};
  int code[30000]={0};
  int ptr=0;
  int code_ptr=0;
  FILE *fp;
  int code_len=0;
  char line[50];
  //命令セット
  char *mama1 = "ママーー！\n"; //>
  char *mama2 = "ママーー！！\n"; //<
  char *mama3 = "ばぶぅ！\n"; //+
  char *mama4 = "ばぶーーー！\n"; //-
  char *mama5 = "マ、マーーー！！\n"; //.
  char *mama6 = "ままああああああ！\n"; //,
  char *mama7 = "赤ちゃんでしゅ。\n"; //[
  char *mama8 = "赤ちゃんでーーしゅ！\n"; //]

  //file読み込み
  if(argc !=2) printf("./mama your_mama_file.mama\n");

  if((fp = fopen(argv[1],"r")) == NULL){ printf("file open error!\n"); return -1;}

  while(fgets(line,sizeof(line),fp)!=NULL){
    if(!strcmp(line,mama1)) code[code_len++]=1;
    else if(!strcmp(line,mama2)) code[code_len++]=2;
    else if(!strcmp(line,mama3)) code[code_len++]=3;
    else if(!strcmp(line,mama4)) code[code_len++]=4;
    else if(!strcmp(line,mama5)) code[code_len++]=5;
    else if(!strcmp(line,mama6)) code[code_len++]=6;
    else if(!strcmp(line,mama7)) code[code_len++]=7;
    else if(!strcmp(line,mama8)) code[code_len++]=8;
  }

  //実行処理
  for(;code_ptr<code_len;code_ptr++){
    switch(code[code_ptr]){
      case 1:
        ptr++;
        break;
      case 2:
        ptr--;
        break;
      case 3:
        buf[ptr]++;
        break;
      case 4:
        buf[ptr]--;
        break;
      case 5:
        putchar(buf[ptr]);
        break;
      case 6:
        buf[ptr] = getchar();
        break;
      case 7:
        if(buf[ptr]==0){
          int j=0;
          for(code_ptr++; j>0 || code[code_ptr] != 8; code_ptr++){
            if(code[code_ptr]==7) j++;
            if(code[code_ptr]==8) j--;
          }
        }
        break;
      case 8:
        if(buf[ptr]!=0){
          int j=0;
          for(code_ptr--; j>0 || code[code_ptr] !=7; code_ptr--){
            if(code[code_ptr]==7) j++;
            if(code[code_ptr]==8) j--;
          }
        }
        break;
    }
  }


  fclose(fp);

  return 0;
}
