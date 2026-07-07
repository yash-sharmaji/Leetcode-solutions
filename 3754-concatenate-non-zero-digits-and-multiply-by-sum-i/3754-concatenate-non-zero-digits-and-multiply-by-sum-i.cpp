class Solution {
public:
    long long sumAndMultiply(int n) {


        if(n==0){
            return 0;
        }
        string answer="";
        bool first=true;
        long long temp=n;
        int sum=0;
        while(temp!=0){
            sum=sum+(temp%10);

            temp/=10;
        }


        while(n!=0){
            if(n%10 !=0){
                answer=answer+to_string(n%10);
            }
            n=n/10;
        }
        for(int i=0,j=answer.size()-1;i<j;i++,j--){
            int temp =answer[i];
            answer[i]=answer[j];
        answer[j]=temp;
        }

        long long f_answer = stoi(answer);
        return f_answer*sum;
    }
};