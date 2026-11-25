#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;

    int dfs(vector<vector<int>>& grid, int r, int c, int id) {

        stack<pair<int,int>> st;

        st.push({r,c});
        grid[r][c] = id;

        int area = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!st.empty()) {

            int row = st.top().first;
            int col = st.top().second;

            st.pop();

            area++;

            for(int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n) {

                    if(grid[nr][nc] == 1) {

                        grid[nr][nc] = id;
                        st.push({nr,nc});
                    }
                }
            }
        }

        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {

        n = grid.size();

        vector<int> size(n*n + 2, 0);

        int id = 2;
        int maxArea = 0;


        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1) {

                    int area = dfs(grid, r, c, id);

                    size[id] = area;

                    maxArea = max(maxArea, area);

                    id++;
                }
            }
        }


        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0) {

                    int currArea = 1;

                    int seen[4];
                    int count = 0;

                    int dr[] = {-1, 1, 0, 0};
                    int dc[] = {0, 0, -1, 1};

                    for(int i = 0; i < 4; i++) {

                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        if(nr >= 0 && nr < n && nc >= 0 && nc < n) {

                            int neighborId = grid[nr][nc];

                            if(neighborId > 1) {

                                bool duplicate = false;

                                for(int j = 0; j < count; j++) {

                                    if(seen[j] == neighborId) {

                                        duplicate = true;
                                        break;
                                    }
                                }

                                if(!duplicate) {

                                    currArea += size[neighborId];

                                    seen[count] = neighborId;
                                    count++;
                                }
                            }
                        }
                    }

                    maxArea = max(maxArea, currArea);
                }
            }
        }

        return maxArea;
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter grid size: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter grid elements (0 or 1):\n";

    for(int r = 0; r < n; r++) {

        for(int c = 0; c < n; c++) {

            cin >> grid[r][c];
        }
    }

    int ans = obj.largestIsland(grid);

    cout << "Largest Island Area: " << ans << endl;

    return 0;
}