#include<bits\stdc++.h>
using namespace std;
static int Pptr = 1;
class City{
	public:
		string Cname;
		int Ctot;
	
	public:
		City(){};
		City(string cname, int ctot) {
			Cname = cname, Ctot = ctot;
		}
};

class Province{
	public:
		string Pname;
		int Ptot;
		int Cnt;
		City city[1000];

	public:
		Province(){};
		Province(string pname){
			Ptot = 0, Pname = pname;
		}
		void getPtot(int tot){
			Ptot += tot;
		}
		void sort_city(Province &pro, int cnt);
		friend bool operator<(const Province &u, const Province &v){
			if(u.Ptot == v.Ptot) return u.Pname < v.Pname;
			return u.Ptot > v.Ptot;
		}
};

class Country {
	public:
		Province province[100];
	
	public:
		Country(){};
		void Sort();
		void Show1();
		void Show2();
};

Country country;
string res = "", infile = "", outfile = "";
ifstream in;
ofstream out;

void Province :: sort_city(Province &pro, int cnt){
	for(int j = 1; j < cnt; j++){
		for(int k = j + 1; k < cnt; k++){
			string tem = "";
			int num = 0;
			if(pro.city[j].Ctot < pro.city[k].Ctot){
				num = pro.city[k].Ctot;
				pro.city[j].Ctot = pro.city[k].Ctot;
				pro.city[k].Ctot = num;
			}
			if(pro.city[j].Ctot == pro.city[k].Ctot){
				if(pro.city[j].Cname > pro.city[j].Cname){
					tem = pro.city[j].Cname;
					pro.city[j].Cname = pro.city[k].Cname;
					pro.city[k].Cname = tem;
				}
			}
		}
	}
}

void Country :: Sort(){
	sort(country.province + 1, country.province + Pptr);
	for(int i = 1; i < Pptr; i++){
		country.province[i].sort_city(country.province[i], country.province[i].Cnt);
	}
}

void Country :: Show1(){
	for(int i = 1; i < Pptr; i++){
		out << country.province[i].Pname << "	" << country.province[i].Ptot << endl;
		for(int j = 1; j < country.province[i].Cnt; j++){
			out << country.province[i].city[j].Cname << "	" << country.province[i].city[j].Ctot << endl;
		}
		out << endl;
	}
}

void Country :: Show2(){
	for(int i = 1; i < Pptr; i++){
		if(country.province[i].Pname == res){
			out << country.province[i].Pname << "	" << country.province[i].Ptot << endl;
			for(int j = 1; j < country.province[i].Cnt; j++){
				out << country.province[i].city[j].Cname << "	" << country.province[i].city[j].Ctot << endl;
			}
			break;
		}
	}
}


int main(int argc, char *argv[]){
	int ok = 0, flag = 0;
	if(argc == 1){
		ok = 1;
	}
	else{
		for(int i = 0; i < strlen(argv[2]); i++){
			if(argv[2][i] == '.'){
				ok = 1;
				break;
			}
		}
	}
	if(ok == 0) res = argv[2];
	infile = "yq_in_04.txt", outfile = "yq_out_04.txt";
	in.open(infile);
	out.open(outfile);
	string P, C, tem;
	int num = 0;
	int Cptr = 1;
	while(in >> P >> C >> num){
		if(P != tem){
			if(tem.length() != 0) country.province[Pptr - 1].Cnt = Cptr; 
			country.province[Pptr].Pname = P;
			tem = P;
			Pptr++;
			Cptr = 1;
		}
		if(num == 0) continue;
		int id = Pptr - 1;
		country.province[id].getPtot(num);
		country.province[id].city[Cptr].Cname = C;
		country.province[id].city[Cptr].Ctot = num;
		Cptr++;
	}
	country.province[Pptr - 1].Cnt = Cptr;
	country.Sort();
	if(ok == 1){
		country.Show1();
	}
	else{
		country.Show2();
	}
	return 0;
}
