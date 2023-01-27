//149. Max Points on a Line
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;
        int maxp=2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int count=2;
                for(int k=0;k<n;k++){
                    //(y2-y1)(x3-x1)==(x2-x1)(y3-y1)
                    if(k!=i && k!=j){
                        if((points[j][1]-points[i][1])*(points[k][0]-points[i][0])==(points[j][0]-points[i][0])*(points[k][1]-points[i][1])) count++;
                    }
                }
                maxp=max(maxp,count);
            }
        }
        return maxp;
    }
};
