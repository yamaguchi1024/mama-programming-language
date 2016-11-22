#include<stdio.h>

int main(int argc,char* argv[]){
  //命令セット
  char *mama1 = "ママーー！\n"; //> 
  char *mama2 = "ママーー！！\n"; //< 
  char *mama3 = "ばぶぅ！\n"; //+ 
  char *mama4 = "ばぶーーー！\n"; //- 
  char *mama5 = "マ、マーーー！！\n"; //. 
  char *mama6 = "ままああああああ！\n"; //, 
  char *mama7 = "赤ちゃんでしゅ。\n"; //[ 
  char *mama8 = "赤ちゃんでーーしゅ！\n"; //] 
  FILE *fp;
  FILE *fm;

  if(argc !=3) printf("./bf2mama your_bf_file your_mama_file\n");
  if((fp = fopen(argv[1],"r")) == NULL){ printf("brainfuck file open error!\n"); return -1;}
  if((fm = fopen(argv[2],"w")) == NULL){ printf("mama file open error!\n"); return -1;}
  
  int c;
  while((c = getc(fp)) != EOF){
    switch(c){
      case '>':
        fprintf(fm,"%s",mama1);
        break;
      case '<':
        fprintf(fm,"%s",mama2);
        break;
      case '+':
        fprintf(fm,"%s",mama3);
        break;
      case '-':
        fprintf(fm,"%s",mama4);
        break;
      case '.':
        fprintf(fm,"%s",mama5);
        break;
      case ',':
        fprintf(fm,"%s",mama6);
        break;
      case '[':
        fprintf(fm,"%s",mama7);
        break;
      case ']':
        fprintf(fm,"%s",mama8);
        break;
    }
  }

  fclose(fp);
  fclose(fm);

  return 0;
}
