// Easy problem. Switch case is fastes.

class Solution {
public:
    bool judgeCircle(string moves) {
        return (count(moves.begin(), moves.end(), 'U') ==
               count(moves.begin(), moves.end(), 'D')) &&
                (count(moves.begin(), moves.end(), 'L') ==
               count(moves.begin(), moves.end(), 'R'));
    }
};

class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> cor = {0, 0};
        for (const auto move : moves){
            switch(move){
                case 'U':
                    cor.second++;
                    break;
                case 'D':
                    cor.second--;
                    break;
                case 'R':
                    cor.first++;
                    break;
                case 'L':
                    cor.first--;
                    break;
            }
        }
        return !(cor.first || cor.second);
    }
};

