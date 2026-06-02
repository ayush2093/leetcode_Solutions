class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land -> Water
                int landFinish = landStartTime[i] + landDuration[i];
                int waterFinish = max(landFinish, waterStartTime[j]) + waterDuration[j];
                ans = min(ans, waterFinish);

                // Water -> Land
                int waterFinishFirst = waterStartTime[j] + waterDuration[j];
                int landFinishSecond = max(waterFinishFirst, landStartTime[i]) + landDuration[i];
                ans = min(ans, landFinishSecond);
            }
        }

        return ans;
    }
};