/*
>s=50 stock, d=10 days, m=2e5 money
>max profit

觀察、性質 !
猜測 ?
作法 :
問題 >

! buy in i, sell in j, profit = a[j]-a[i]
: in a day, sell first, buy then
! total money in the day is a[sell] today - a[buy] today + ori
? dp[i][j]
*/