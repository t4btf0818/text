#include<bits/stdc++.h>
using namespace std;
int main(int argc,char *argv[]){
	if(argc==3){
		struct map {
    char area[10];
    char city[15];
    int num;
    
} a[200], *p;
    FILE* fp, * fp2;
    int i;
    p=a;
    for (i = 0; i <200; i++, p++) {
        fscanf(fp, "%s	%s	%d\n", p->area, p->city, &p->num);
    }
    p=a;
    for (i = 0; i <200; i++, p++) {
        if (a[i].num == 0)
            {
            continue;
			}
        if(i==0){
            fprintf(fp2,"%s\n%s	%d\n", p->area, p->city, p->num);
			}
        else {
            if (strcmp(a[i].area,a[i-1].area)==0)
                {
                fprintf(fp2,"%s\t%d\n", a[i].city, a[i].num);
				}
            else{
                fprintf(fp2,"\n%s\n%s\t%d\n", a[i].area, a[i].city, a[i].num);
            }
                
        }
        
    }
    fclose(fp);
    fclose(fp2);
    return 0;

	}
	else if(argc==4){
	freopen("C:\\Users\\20662\\Desktop\\shiyaner\\yq_in_03.txt","r",stdin);
	freopen("C:\\Users\\20662\\Desktop\\shiyaner\\yq_out_03.txt","w",stdout);
	string where1,where2,shengfen;
	int people2;
	int k=strlen(argv[3]);
	for(int i=0;i<k;i++){
		shengfen.push_back(argv[3][i]);
	}
	map<string,vector<pair<string,int> > > mp1;
	while(cin>>where1>>where2>>people2){
		mp1[where1].push_back(pair<string,int>(where2,people2));
	}
	cout<<shengfen<<endl;
	for(auto it:mp1){
		if(it.first==shengfen){
			for(auto it2:it.second){
			cout<<it2.first<<" "<<it2.second<<endl;
		}
		}
	}
	}
} 
