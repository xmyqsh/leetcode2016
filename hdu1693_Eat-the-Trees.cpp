/*
 * 给定n*m的格子，要求用闭合回路铺满非0的格子，问有多少种铺法？(注：不限制回路数目)
 *
 * naive: (n*m)!
 * 状态压缩插头dp：n*m*(2**m)
 * */
#include<cstdio>
#include<iostream>
#include<cstring>
#define clr(x) memset(x,0,sizeof(x))
#define LL long long
using namespace std;
LL dp[20][20][1<<12+1];
int mp[100][100];
int main()
{
  int T,n,m,k,t1,t2,kase=0;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d",&mp[i][j]);
    clr(dp);
    // 右上角初始状态0，用于后面的转移
    dp[0][m][0]=1;
    for(int i=1;i<=n;i++)
    {
      for(int k=0;k<(1<<m);k++)
      {
        // 由i-1行的末尾状态k，转换为第i行开头的状态k<<1; 压缩状态的二进制为从左到右，从L到H
        dp[i][0][k<<1]=dp[i-1][m][k];
      }
      for(int j=1;j<=m;j++)
      {
        // k为轮廓线插头状态
        for(int k=0;k<(1<<(m+1));k++)
        {
          // 第j和j-1列的状态掩码
          t2=1<<j;
          t1=1<<(j-1);
          // 用穿过cell的概念一句话概括：
          // 对于某个特定方案中的一个valid的cell有且仅有两个插头穿过，道理很简单，有进就得有出
          // （注：穿过cell和穿轮廓线不是一个概念，穿轮廓线只需一个插头，穿过cell需要两个插头）
          // 有：valid的cell必须被插头穿过
          // 仅有：valid的cell不能被多次穿过
          if(mp[i][j])
          {
            // 轮廓线上只有一个插头时，可保持压缩状态k不变，进行转移, 也可反转压缩状态k^t1^t2，进行转移;
            // 注：列j-1到列j的转移，k上的掩码t1,t2必须同时翻转或同时不反转，具体画图验证
            if(((k&t2)==0 && (k&t1)!=0) || ((k&t2)!=0 && (k&t1)==0))
              dp[i][j][k]+=dp[i][j-1][k];
            // 轮廓线上有两个插头(最多两个插头)时，压缩状态k必须在掩码t1,t2上同时反转到k^t1^t2，具体画图验证
            // 轮廓线上没有插头时，压缩状态k必须在掩码t1,t2上同时反转到k^t1^t2，具体画图验证
            dp[i][j][k]+=dp[i][j-1][k^t1^t2];
            // 轮廓线上有两个插头(左插头和上插头)时，不能合法转移是显而易见的，从一个插头进来，又从另一个插头出去了，
            // 该cell必定没有下插头和右插头穿过
            //
            // 问：轮廓线上没有插头时，为什么不能合法转移
            // dp[i][j][k]+=dp[i][j-1][k]
            // 答：每一个valid的cell必须有插头穿过
          }
          else
          {
            // 障碍物上没有插头时，可合法转移
            if((k&t1)==0&&(k&t2)==0) dp[i][j][k]+=dp[i][j-1][k];
          }
        }
      }
    }
  printf("Case %d: There are %lld ways to eat the trees.\n",++kase,dp[n][m][0]);
  }
  return 0;
}
