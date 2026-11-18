class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int totalLitter = 0;

        vector<vector<int>> litter(m, vector<int>(n, -1));

        // Find start and assign bit positions to litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter[i][j] = totalLitter++;
                }
            }
        }

        if (totalLitter == 0) return 0;

        int target = (1 << totalLitter) - 1;
        int maskCount = 1 << totalLitter;

        // Maximum energy previously seen for each position + mask
        vector<int> bestEnergy(m * n * maskCount, -1);

        // State: row, col, mask, remaining energy, moves
        struct State {
            int r, c, mask, e, moves;
        };

        queue<State> q;

        int startIdx = (sr * n + sc) * maskCount;

        bestEnergy[startIdx] = energy;
        q.push({sr, sc, 0, energy, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int mask = cur.mask;
            int e = cur.e;
            int moves = cur.moves;

            if (mask == target) {
                return moves;
            }

            if (e == 0) continue;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                if (classroom[nr][nc] == 'X') {
                    continue;
                }

                int newEnergy = e - 1;
                int newMask = mask;

                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                if (classroom[nr][nc] == 'L') {
                    newMask |= (1 << litter[nr][nc]);
                }

                int idx = (nr * n + nc) * maskCount + newMask;

                // Dominance pruning
                if (newEnergy <= bestEnergy[idx]) {
                    continue;
                }

                bestEnergy[idx] = newEnergy;

                q.push({
                    nr, nc, newMask,
                    newEnergy, moves + 1
                });
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna