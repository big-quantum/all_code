#include<bits/stdc++.h>
using namespace std;
int n,tot;
string s;
int main(){
	cin>>n;
	while(n>0){
		tot++;
		int num=n%10;
		if(num==9){
			if(tot==1) s=s+"XI";
			if(tot==2) s=s+"CX";
			if(tot==3) s=s+"MC";
			n=n/10;
			continue; 
		}
		if(num>=5){
			if(tot==1){
				
				while(num!=5){
					s=s+"I";
					num--;
				}
				s=s+"V";
			}
			if(tot==2){
				
				while(num!=5){
					s=s+"X";
					num--;
				}
				s=s+"L";
			}
			if(tot==3){
				
				while(num!=5){
					s=s+"C";
					num--;
				}
				s=s+"D";
			}
			n=n/10;
			continue;
		}
		if(num==4){
			if(tot==1) s=s+"VI";
			if(tot==2) s=s+"LX";
			if(tot==3) s=s+"DC";
			n=n/10;
			continue; 
		}if(num>=0){
			if(tot==1) while(num!=0){
				s=s+"I";
				num--;
			}
			if(tot==2) while(num!=0){
				s=s+"X";
				num--;
			}
			if(tot==3) while(num!=0){
				s=s+"C";
				num--;
			}
			if(tot==4) while(num!=0){
				s=s+"M";
				num--;
			}
			n=n/10;
			continue;
		}
	}
	for(int i=s.size()-1;i>=0;i--) cout<<s[i];
	return 0;
}
/*while(n>0){
		tot++;
		int num=n%10;
		if(num==9){
			if(tot==1) s=s+"IX";
			if(tot==2) s=s+"XC";
			if(tot==3) s=s+"CM";
			n=n/10;
			continue; 
		}
		if(num>=5){
			if(tot==1){
				while(num!=5){
					s=s+"I";
					num--;
				}
				s=s+"V";
			}
			if(tot==2){
				while(num!=5){
					s=s+"X";
					num--;
				}
				s=s+"L";
			}
			if(tot==3){
				while(num!=5){
					s=s+"C";
					num--;
				}
				s=s+"D";
			}
			n=n/10;
			continue;
		}
		if(num==4){
			if(tot==1) s=s+"IV";
			if(tot==2) s=s+"XL";
			if(tot==3) s=s+"CD";
			n=n/10;
			continue; 
		}if(num>=0){
			if(tot==1) while(num!=0){
				s=s+"I";
				num--;
			}
			if(tot==2) while(num!=0){
				s=s+"X";
				num--;
			}
			if(tot==3) while(num!=0){
				s=s+"C";
				num--;
			}
			if(tot==4) while(num!=0){
				s=s+"M";
				num--;
			}
			n=n/10;
			continue;
		}
	}*/
