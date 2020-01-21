///Elgamal Cryptosystem,Rabin CryptoSystem,RSA,RSA Signature,Elgamal Signature,DSS
#include<bits/stdc++.h>

using namespace std;

long long int bigMod(long long int b,long long int p, long long int M) ///this function is common for all
{
    if(p==0) return 1;

    if(p%2 == 0){
        long long int rem = bigMod(b,p/2,M);

        return ((rem%M) * (rem%M))%M;
    }

    else{
        return ((b%M)*(bigMod(b,p-1,M)%M))%M;
    }
}


long long int Power(long long int base, long long int power,long long int n)///this function used where primitive root need
{
    long long int mul = 1;

    for(int i=1;i<=power;i++)
    {
        mul = (mul*base) % n;
    }

    return mul;
}

long long int primitive_root_find(long long int n) ///this function used where primitive root need
{
    for(int i=2; i<n; i++)
    {
        bool check = true;

        for(int j=1; j<n-1; j++)
        {
          long long int val = Power(i,j,n); // x=a^i calculating

          if(val==1) check = false;
        }
        if(check) return i;
    }

    return 1;
}

void Elgamal() ///this function Only used in Elgamal cryptosystem
{
   long long int p,e,d=3,e1,e2,P,C1,C2,P1,r; // e is primitive root of n

    cout << "Enter Prime Number : ";
    cin >> p ;

   e = primitive_root_find(p);

   e1 = e;

   e2 = bigMod(e1,d,p);

   //cout << e1 << " " << e2;

    cout << "Enter Plaintext & 'r' : ";

    cin >> P >> r;

    C1 = bigMod(e1,r,p);

    C2 =  bigMod(e2,r,p);

    C2 = (P*C2)%p;

    cout << "Cipher Text C1 = " <<  C1 << "\n Cipher Text C2 = " << C2 << endl;

    long long int P2 = bigMod(C1 , p-d-1,p);

    P1 = (C2 * P2) % p;

    cout << "Decryption of Cipher Text : " << P1 << endl;
}

long long int CRT(long long int a1, long long int a2,long long int m1, long long int m2)
///this function only used in rabin cryptosystem
{
    long long int M , M1 , M2, InverseM1 , InverseM2 , P;

    M = m1 * m2;

    M1 = (M/m1);

    M2 = (M/m2);

    InverseM1 = bigMod(M1 , m1-2 , m1);

    InverseM2 = bigMod(M2 , m2-2 , m2);

    P = ((a1 * M1 * InverseM1)%M + (a2 * M2 * InverseM2)%M)%M;

    return P;

}

void Rabin() /// this function only used in rabin cruptosystem
{
    long long int n,p,q,P,C,a1,a2,b1,b2,P1,P2,P3,P4;//two prime number should (4*k + 3)

    cout << "Enter two prime p & q : ";

    cin >> p >> q;

    n = p*q;

    cout << "Enter Plain Text : ";

    cin >> P;

    C = bigMod(P,2,n);

    cout << "Cipher Text = " << C << '\n';

    a1 = bigMod(C, (p+1)/4, p);

    a2 = p - a1;

    b1 = bigMod(C, (q+1)/4, q);

    b2 = q - b1;

    P1 = CRT(a1,b1,p,q);

    P2 = CRT(a1,b2,p,q);

    P3 = CRT(a2,b1,p,q);

    P4 = CRT(a2,b2,p,q);

    cout << "Decryption of the Cipher Text : P1 = ";
    cout << P1 << "\nP2 = " << P2 << "\nP3 = " << P3 << "\nP4 = " << P4 << '\n';

}

void RSA()
{
    long long int n,p,q,phin,e,d,C,P,M;

    cout << "Enter two prime p and q ";

    cin >> p >> q;

    n = p*q;

    phin = (p-1)*(q-1);

    for(long long int i=2 ; i<phin ; i++){ ///this for finding coprime of phi(n)
        if(__gcd(phin,i)==1){
            e = i;
            break;
        }
    }

    //e = 13;

    //d = bigMod(e,phin-2,phin);

    long long int qo, r1 = phin, r2 = e, r ,t1 = 0 ,t2 = 1,t;

    while(r2>0){
        qo = r1 / r2;
        r = r1 - (qo*r2);
        r1 = r2; r2 = r;

        t = t1 - (qo*t2);
        t1 = t2; t2 = t;
    }

    d = (t1+phin) % phin;

    //cout << n << " " << phin << " " << d << endl;
    cout << "Plain Text : ";

    cin >> P;

    C = bigMod(P,e,n);

    cout << "Cipher Text = " << C << '\n';

    M = bigMod(C,d,n);

    cout << "Decrypted Message : " << M << '\n';
}

void RSASignature()
{
    long long int n,p,q,phin,e,d,S,V,M;

    cout << "Enter two prime p and q ";

    cin >> p >> q;

    n = p*q;

    phin = (p-1)*(q-1);

    for(long long int i=2 ; i<phin ; i++){ ///this for finding coprime of phi(n)
        if(__gcd(phin,i)==1){
            e = i;
            break;
        }
    }

    long long int qo, r1 = phin, r2 = e, r ,t1 = 0 ,t2 = 1,t;

    while(r2>0){
        qo = r1 / r2;
        r = r1 - (qo*r2);
        r1 = r2; r2 = r;

        t = t1 - (qo*t2);
        t1 = t2; t2 = t;
    }

    d = (t1+phin) % phin;

    cout << "Enter the message : ";

    cin >> M;

    S = bigMod(M,d,n);

    V = bigMod(S,e,n);

    cout << "Signature of the message : " << S <<"\nVerification : " << V << '\n';

}

void ElgamalDigitalSignature()
{
    long long int p,d=3,e1,e2,M,S1,S2,V1,V2,r,rInverse; // e is primitive root of n

    cout << "Enter Prime Number : ";
    cin >> p ;

   e1 = primitive_root_find(p);

   e2 = bigMod(e1,d,p);

   //cout << e1 << " " << e2;

    cout << "Enter Message : ";

    cin >> M;

    for(long long int i=2;i<p-1;i++){
        if(__gcd(p-1,i)==1){
            r = i;
            break;
        }
    }
    //r = 9;
    S1 = bigMod(e1,r,p);

    long long int q,r1,r2,rr,t1=0,t2=1,t;

    r1 = p-1; r2 = r;

    while(r2>0)
    {
        q = r1/r2;
        rr = r1 - (q*r2);
        r1 = r2 ; r2 = rr;

        t = t1 - (q*t2);
        t1 = t2; t2 = t;
    }

    rInverse = (t1+p-1) % (p-1);
    //cout << S1 << " " << rInverse << '\n';

    S2 = (((M-(d*S1))%(p-1)) * rInverse) %(p-1);

    S2 = (S2 + (p-1)) % (p-1);

    V1 = bigMod(e1,M,p);

    V2 = (bigMod(e2,S1,p) * bigMod(S1,S2,p))%p;

    cout << "Signature S1 = " << S1 << "\nSignature S2 = " << S2 << '\n';
    cout << "Verification V1 = " << V1 << "\nVerification V2 = " << V2 << '\n';
}

void digitalSignatureStandard()
{
     long long int p,q,e0,e1,e2,d=61,r,S1,S2,V,hM,rInverse,S2Inverse;

     cout << "Enter two prime number p,q : ";

     cin >> p >> q;

     e0 = primitive_root_find(p);

     e1 = bigMod(e0,(p-1)/q,p);

     e2 = bigMod(e1,d,p);

     for(long long int i=2;i<q;i++){
        if(__gcd(q,i)==1){
            r = i;
            break;
        }
    }

     //r = 61;

     cout << e0 << ' '  << e1 << ' ' << e2 << '\n';

     S1 = bigMod(e1,r,p) % q;

     rInverse = bigMod(r,q-2,q);

     cout << "Enter the message : ";

     cin >> hM;

     S2 = ((hM+(d*S1))%q*rInverse)%q ;

     S2Inverse = bigMod(S2,q-2,q);

     V = ((bigMod(e1,hM*S2Inverse,p) * bigMod(e2,S1*S2Inverse,p))%p)%q;

     cout << "Signature S1 : " << S1 << "\nSignature S2 : " << S2 << '\n';

     cout << "Verification V : " << V << '\n';
}

int main()
{
    //Elgamal();

    //Rabin();

    //RSA();

    //RSASignature();

    //ElgamalDigitalSignature();

    digitalSignatureStandard();


    return 0;
}
/*
Input For Elgamal:
Prime Number = 11 ,Plaintext = 7 , choose 'r' = 4

Output: C1 = 5 , C2 = 6 , P = 7;
*/

/*
Input For Rabin:

p =23 , q = 7, plaintext P = 24

output :

C = 93 , P1 = 116 , P2 = 24, P3 = 137 , P4 = 35

*/
/*
Input For RSA:
p = 7 q =11, plaintext,P=5
output: C = 47
*/
