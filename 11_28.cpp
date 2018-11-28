#include <bits/stdc++.h>
using namespace std;
//const int maxn=10000;
//vector<int> v[maxn];
// int main()//int argc, char const *argv[])
// {
    /* code */
    // int a=100;
    // printf("%d",a);
    // p.push_back(10);
    // printf("%d\n",p.size());
    // printf("%d",p[0]);
    /*
    struct Edge{
        int t ,val;
        Edge(int tt=0,int tv=0)
        {
            t=tt;
            val = tv;
        }//构造函数（结构体赋值简便）
    };
    int x,y,z;
    v[x].push_back(Edge(y,z));
    for(int i=v[x].size();i>=0;i--)
    {
        Edge tx =v[x][i];
        int ty=tx.y,tz=tx.z;
    }
    */
   //https://www.luogu.org/problemnew/show/P1328
   const int MAXN = 200 + 10;
int n, na, nb, a[MAXN], b[MAXN], cnta, cntb;
int vs[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}}; //得分表的处理 
int main()
{
    cin >> n >> na >> nb;
    for(int i = 0; i < na; i++) cin >> a[i];
    for(int i = 0; i < nb; i++) cin >> b[i];
    for(int i = 0; i < n; i++)
    {
        cnta += vs[a[i % na]][b[i % nb]]; //周期循环 
        cntb += vs[b[i % nb]][a[i % na]];
    }
    cout << cnta << " " << cntb << endl;
    return 0;
}
    


//==========================================================
//https://www.luogu.org/problemnew/show/P1865
#include<bits/stdc++.h>
using namespace std;
// bool IsPrime(int n){
// for(int i = 2; i <=sqrt(n); i++){
// if(n % i == 0){
// return false;
// break;
// }
// else
// return true;
// }
// }

bool IsP_rime(int num)	
{
	if(num==1)
    {
        return false;
    }
    for (int i = 2; i <=sqrt(num); i++)		
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
    // while(true)
    // {
    //     int x;
    //     cin>>x;
    //     cout<<"----"<<IsP_rime(x)<<"  "<<IsPrime(x)<<endl;
    // }
    int m,n,cnt=0;
    cin>>m>>n;
    int l,cm;
    for(int i=0;i<=m;i++)
    {
        
        cin>>l>>cm;
        for(int j=l;j<=cm;j++)
        {
        if(IsP_rime(j))
            {
                cnt++;
            }
        }
    if(l>=1&&cm<=n)printf("%d",cnt);
    else printf("Crossing the line");
    cnt=0;
    }
    
}
//===================================================================
//https://www.luogu.org/problemnew/show/P1022
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//以防万一用long long 
char x; ll coe,value,opp=1;//coe表示系数，value表示值，opp表示在等号左边还是右边 
double ans;
int main(){
    char c=getchar();//为了节省空间当然要在线 
    ll cur=0,sign=1; bool value_gotten=false;
    //cur为当前读入的数值，
    // sign表示当前数值符号，
    // value_gotten是一个标记变量，
    //字面意思是是否读入过数值，
    while (true){
        if (c>='a' && c<='z'){
            x=c; if (cur==0 && !value_gotten) coe+=opp*sign,value_gotten=false; 
            //如果cur为0又读入了变量名称有两种情况：一时+0x或-0x，另一种是默认系数为1，
            //value_gotten专门判断这两种情况 
            else coe+=opp*sign*cur,cur=0,sign=1,value_gotten=false;
        }
        else if (c=='-') value+=-opp*sign*cur,cur=0,sign=-1,value_gotten=false;
        //如果是减号把当前数值加入值（如果之前是变量则当前数值为0，加入也没有影响），
        //并清空当前数值，设value_gotten为false，符号修改为负 
        else if (c=='+') value+=-opp*sign*cur,cur=0,sign=1,value_gotten=false;
        //加号和减号一样，只是把符号修改为正 
        else if (c>='0' && c<='9') cur=cur*10+c-'0',value_gotten=true;
        //如果是数字，就对cur进行计算，并把value_gotten设为true 
        else if (c=='=') value+=-opp*sign*cur,cur=0,sign=1,opp=-opp,value_gotten=false;
        //等号和加减号差不多，只是要把opp设为负 
        else {value+=-opp*sign*cur;break;}//最后的值累加上去 
        c=getchar();
    }
    ans=double(value)/coe;//计算ans 
    printf("%c=%.3lf",x,ans==0?abs(ans):ans);
    //这涉及一个很坑的地方：C++里0除以一个负数值为-0，专门避免这种情况 
    return 0;
}