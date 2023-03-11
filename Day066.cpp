// 2187. Minimum Time to Complete Trips
// You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

// Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

// You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.
  
// Constraints:

// 1 <= time.length <= 10^5
// 1 <= time[i], totalTrips <= 10^7


class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0,
        r=totalTrips*(long long)time[0],
        ans=r;
        while(l<r){
            long long mid=(l+r)/2;
            long long count=0;
            for(int i=0;i<time.size();++i) count+=mid/time[i];    
            
            if(count>=totalTrips){
                ans=min(ans,mid);
                r=mid;
            }else l=mid+1;
        }
        return ans;        
    }
};
