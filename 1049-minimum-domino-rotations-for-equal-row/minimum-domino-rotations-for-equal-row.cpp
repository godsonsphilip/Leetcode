class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int min_rot = 0;
        int m1 = 0, m2 = 0;
        auto tempt = tops;
        auto tempb = bottoms;

        auto tempt1 = tops;
        auto tempb1 = bottoms;

        map<int, int> m;
        for (auto& i : tops) {
            m[i]++;
        }

        for (auto& i : bottoms) {
            m[i]++;
        }

        
        int t = -1;
        for (auto it = m.begin(); it != m.end(); ++it) {
            int k = it->first;
            int v = it->second;
            if (v >= n) {
                t = k;
                break;
            }
        }
        cout<<t;

        if(t==-1) return -1;

        // Case-1 : Tops matching:
        for(int i = 0; i<n; i++){
            if(tempt[i]==t) continue;
            else{
                if(tempb[i]==t){
                    swap(tempt[i], tempb[i]);
                    m1++;
                    continue;
                }
                else{return -1;}
            }
        }

        //Case-2: Bottoms:
        for(int i = 0; i<n; i++){
            if(tempb1[i]==t) continue;
            else{
                if(tempt1[i]==t){
                    swap(tempt1[i], tempb1[i]);
                    m2++;
                    continue;
                }
                
            }
        }

        min_rot = min(m1, m2);

        return min_rot;
    }
};