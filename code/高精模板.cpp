#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long p[505],len;
	char s[505];
}num1,num2;
int num3;
node double_addition_double(node a,node b){
	node c;
	c.len=max(a.len,b.len);
	for(int i=1;i<=c.len;i++){
        c.p[i]=c.p[i]+a.p[i]+b.p[i];
        c.p[i+1]=c.p[i]/10;
        c.p[i]=c.p[i]%10;
    }
    while(c.p[c.len+1]>0) c.len++;
    return c;
}
node double_addition_float(node a,int b){
	a.p[1]+=b;
	for(int i=1;i<=a.len;i++){
        a.p[i+1]=a.p[i]/10;
        a.p[i]=a.p[i]%10;
    }
    while(a.p[a.len+1]>0) a.len++;
    return a;
}
long long float_addition_float(int a,int b){
	return a+b;
}
node double_subtraction_double(node a,node b){
	if(b.len>a.len||(a.len==b.len&&a.s>b.s)){
    	printf("-");
    	swap(a.s,b.s);
    	swap(a.len,b.len);
    }
	node c;
	c.len=max(a.len,b.len);
	for(int i=1;i<=c.len;i++){
        c.p[i]=c.p[i]+a.p[i]-b.p[i];
        if(c.p[i]<0) c.p[i]=c.p[i]+10,c.p[i+1]-=1;
    }
    while(c.p[c.len+1]>0) c.len++;
    return c;
}
node double_division_double(node a,node b){
	node c;
	c.len=a.len+b.len-1;
    for(int i=1;i<=a.len;i++){
    	for(int j=1;j<=b.len;j++){
    		c.p[i+j-1]+=a.p[i]*b.p[j];
    		c.p[i+j]+=c.p[i+j-1]/10;
    		c.p[i+j-1]%=10;
		}
	}
    while(c.p[c.len+1]>0) c.len++;
    return c;
}
node double_division_float(node a,int b){
	for(int i=1;i<=a.len;i++) a.p[i]*=b;
    for(int i=1;i<=a.len;i++){
    	a.p[i+1]+=a.p[i]/10;
    	a.p[i]%=10;
    }
    while(a.p[a.len+1]>0) a.len++;
    return a;
}
node double_multiplication_float(node a,int b){
	int r=0;
	for(int i=a.len;i>0;i--){
    	r=r*10+a.p[i];
    	a.p[i]=r/b;
    	r=r%b;
    }
    while(a.p[a.len]==0&&a.len>1) a.len--;
    return a;
}
void write(node a){
    for(int i=a.len;i>0;i--){
        printf("%d",a.p[i]);
    }
    cout<<endl;
}
void read(node &a){
    scanf("%s",a.s+1);
    a.len=strlen(a.s+1);
    for(int i=1;i<=a.len;i++){
        a.p[i]=a.s[a.len-i+1]-'0';
	}
}
int main(){
	read(num1);
	read(num2);
	cin>>num3;
	write(double_addition_double(num1,num2));
	write(double_subtraction_double(num1,num2));
	write(double_division_double(num1,num2));
	write(double_division_float(num1,num3));
	write(double_multiplication_float(num1,num3));
	return 0;
}
