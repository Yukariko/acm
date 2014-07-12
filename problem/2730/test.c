#include <time.h>
struct tm limit_day, submit_day, temp_day;
time_t limit_time,submit_time,diff_time;
int year,check;
long long abst(time_t n){return n>=0?n:-n;}
main(i)
{
  for(gets(&i);~scanf("%d/%d/%d %d/%d",&limit_day.tm_mon,&limit_day.tm_mday,&year,&submit_day.tm_mon,&submit_day.tm_mday);)
  {
    limit_day.tm_mon--;submit_day.tm_mon--;
    limit_day.tm_year=year-1900;
    limit_time=mktime(&limit_day);
    check=0;
    for(i=-1;i<=1;i++)
    {
      submit_day.tm_year=year+i-1900;
      temp_day = submit_day;
      submit_time=mktime(&temp_day);
      if(i==0&&temp_day.tm_mday!=submit_day.tm_mday){check=1;puts("OUT OF RANGE");break;};
      diff_time=submit_time-limit_time;
      diff_time/=86400;
      if (abst(diff_time) < 8) 
      {
        check=1;
        if (diff_time == 0) puts("SAME DAY");
        else printf("%d/%d/%d IS %lld %s %s\n",submit_day.tm_mon+1,submit_day.tm_mday,year+i,abst(diff_time),abst(diff_time)==1?"DAY":"DAYS",diff_time>0?"AFTER":"PRIOR");
      }
    }
    if(!check) puts("OUT OF RANGE");
  }
}
