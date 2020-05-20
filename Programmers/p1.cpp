using namespace std;

long long gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

long long solution(int w, int h) {
    //long long casting
    long long answer = (long long)w * (long long)h;
    
    answer -= (w + h - gcd(w, h));
    
    return answer;
}