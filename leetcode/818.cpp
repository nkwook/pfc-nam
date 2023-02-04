
class Solution {
public:
  int racecar(int target) {
    unordered_map < int, unordered_map<int, int> > m;
    // position, speed / instruction length

    queue<tuple<int, int, int>> Q;
    // position, speed, length
    Q.push(make_tuple(0, 1, 0));

    while (!Q.empty()) {

      tuple<int, int, int> t = Q.front();
      Q.pop();
      int position = get<0>(t);
      int speed = get<1>(t);
      int length = get<2>(t);

      if (position == target) {
          return length;
      }


      if (m[position][speed] || position < 0 || position > 2*target) {
        continue;
      }

      m[position][speed]=1;

    
        Q.push(resultA(position, speed, length));

        if(speed <0 || position + speed > target){
            Q.push(resultR(position, speed, length));
        }
        // key idea: determine when to call R, think about whether it is really needed?
    }
    //should not be here
    return -1;
  }

  tuple<int, int, int> resultA(int p, int s, int l) {
    return make_tuple(p+s, s*2, l+1);
  }

  tuple<int, int, int> resultR(int p, int s, int l) {
      int newSpeed=-1;
      if (s<0){
          newSpeed=1;
      }
    return make_tuple(p, newSpeed, l+1);
  }
};