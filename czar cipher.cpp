#include <bits/stdc++.h>
using namespace std;

char letters[28]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ "};

int get_position(char x){
    int position,i;

    for(i=0;i<27;i++){
        if(letters[i]==x){
            position=i;
            break;
        }
    }
    return position;
}

void cipher_text(){

    int len,i,p,d,k;
    char msg[1001];
    char cipher[1001];

    cout << "Enter the text: ";
    cin.ignore(1);
    gets(msg);
    cout << "\nEnter the number of letters to shift(value of K): ";
    cin >> k;

    len=strlen(msg);

    for(i=0;i<len;i++)
        msg[i]=toupper(msg[i]);

    for(i=0;i<len;i++){
        p=get_position(msg[i]);
        d=(p+k)%27;
        cipher[i]=letters[d];
    }
    cipher[len]='\0';

    cout << endl << "The Cipher text is: " << cipher << endl;
}

void decipher_text(){

    int len,i,p,d,r,k;
    char msg[1001];
    char decipher[1001];

    cout << "Enter the text: ";
    cin.ignore(1);
    gets(msg);

    len=strlen(msg);

    for(i=0;i<len;i++)
        msg[i]=toupper(msg[i]);

    cout << endl << "The Deciphered results:" << endl << endl;

    for(k=1;k<=26;k++){
        for(i=0;i<len;i++){
            p=get_position(msg[i]);
            d=p-k;
            if(d<0){
                d=abs(d);
                d=27-d;
            }
            r=d%27;
            decipher[i]=letters[r];
        }
        decipher[len]='\0';

        cout << "Case " << k << ": " << decipher << endl;
    }
}

int main(){

    int s;

    cout << "1. Cipher\n2. Decipher\n\nSelect: ";
    cin >> s;
    cout << endl;

    if(s==1)
        cipher_text();
    else if(s==2)
        decipher_text();
    else
        return 0;

    cout << "\n\n\n\n\n\n";

    return 0;
}
