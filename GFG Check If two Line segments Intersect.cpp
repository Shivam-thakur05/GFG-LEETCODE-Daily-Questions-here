class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        double m1=double(q1[1]-p1[1])/double(q1[0]-p1[0]);
        double m2=double(q2[1]-p2[1])/double(q2[0]-p2[0]);
        if(m1==m2){
            return "false";
        }
        // this is the first line points p2 and q2
        bool check1=p2[1]-p1[1]-m1*(p2[0]-p1[0])>0?true : false;
        bool check2=q2[1]-p1[1]-m1*(q2[0]-p1[0])>0?true : false;
        // this is the first line points p1 and q1
        bool check3=p1[1]-p2[1]-m2*(p1[0]-p2[0])>0?true : false;
        bool check4=q1[1]-p2[1]-m2*(q1[0]-p2[0])>0?true : false;
        
        if((check1==true && check2== true) || (check1==false && check2== false)
        || (check3==true && check4== true) || (check3==false && check4== false)){
        return "false";
        }
        return "true";
    }
};
