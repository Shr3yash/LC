//^recursn

int pow(int a, int b){
  if(b=0)
    return 1;
  else if(b=1)
    return a;
  int poww=pow(a,b/2);
  if(b%2==0)
    poww=pow*pow;
  else if(b%2!=0)
    poww=a*pow*pow;
}

//sUrt

int surt(int& arr, int n)
{
if(n==0||n==1)
  return;
for(int i = 0; i<n;i++){
  if(arr[i]>arr[i+1]){
    swap(arr[i], arr[i+1]);}}
  surt(arr, n-1);
}


