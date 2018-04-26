#include "CircularInt.hpp"
    int  gRange(int start,int end,int cur){
        int modulo=end-start+1;
        cur=cur%modulo;
        if(cur<0)cur=cur+modulo;
        for(int i = start ; i <= end ; i++ ){
            if(i%modulo==cur){
                return i;
            }
        } throw string ("error converting to Circularint");
    }

    CircularInt::CircularInt(int start_point,int end_point){
        start=start_point;
        end=end_point;
        cur=start_point;
        modulo=end-start+1;

    };
    int CircularInt::get_start()const{
        return this->start;
    }
    int CircularInt::get_end()const{
        return this->end;
    }

    int CircularInt::get_cur()const{
        return this->cur;
    }
    void CircularInt::set_cur(int a){
        this->cur=inRange(a);
    }
    int CircularInt::inRange(int result){
     result=result%modulo;
        if(result<0)result=result+modulo;
     for (int i = start; i <end ; ++i) {
        if(i%modulo==result){
            return i;
        }
    } return result;
    }

    int CircularInt::operator++(int) {
        int temp=cur;
        if(cur==end) {
            cur=start;
        } else {
            cur++;
        }
        return temp;
    };

    int CircularInt::operator--(int) {
        int temp=cur;
        if (cur == start) {
            cur = end;
        } else {
            cur--;
        }
        return temp;
    }
    CircularInt& CircularInt::operator+=(int a){
        if(a<0)return ((*this)-=-a);
        int mod=a%(end-start+1);
        for(int i=0; i<mod; i++){
            (*this)++;
        }
        return *this;
    }
    CircularInt& CircularInt::operator-=( int a){
    if(a<0)return ((*this)-=-a);
    int mod=a%(end-start+1);
    for(int i=0; i<mod; i++){
        (*this)--;
    }
    return *this;
    }
    int  CircularInt::operator-() {
        int loop=cur%(end-start+1);
        return end-loop;


    }
    CircularInt& CircularInt::operator=(int a){
        if(a>=start&&a<=end){
            this->cur=a;
            return *this;
        }else{
            int modulo=(end-start+1);
            a=a%modulo;
            for(int i=start;i<=end;i++){
                if(i%modulo==a){
                    this->cur=i;
                    return *this;
                }
            }

        } throw string("error assingning into CircularInt");
    }

     int operator-( int a,CircularInt& c) {
        int modulo=(c.end-c.start+1);
         a=a-c.cur;
         while(a<0){
             a=a+modulo;
         }
         a=a%modulo;
         for(int i=c.start;i<=c.end;i++){
             if(i%modulo==a){
                 return i;
             }
         }throw string("error subtracting  CircularInt");
    }
    int operator+(CircularInt& a,CircularInt& b){
        int temp=a.cur+b.cur;
            return gRange(a.start,a.end,temp);

    }
    int operator-(CircularInt& c,int a){
        int modulo=(c.get_end()-c.get_start()+1);
        a=a-c.cur;
        while(a<0){
            a=a+modulo;
        }
        a=a%modulo;
        for(int i=c.get_start();i<=c.get_end();i++){
            if(i%modulo==a){
                return i;
            }
        }  throw string("error negating  CircularInt");
    }
    CircularInt& CircularInt::operator*=(int a){
        this->cur=gRange(this->start,this->end,a*this->cur);
        return *this;
    }
      ostream& operator<<(ostream& output,const CircularInt& x){
    output<<x.cur;
        return  output;
    }
    int CircularInt::operator+(int a){
        return inRange(cur+a);
    }
    int CircularInt::operator-(int a){
        return inRange(cur-a);
    }
    int CircularInt::operator*(int a){
        return inRange(a*cur);
    }
    CircularInt&CircularInt::operator--(){
        cur=inRange(--cur);
	return(*this);
    }
    CircularInt&CircularInt::operator++(){
        cur=inRange(++cur);
        return *this;
    }
    CircularInt&CircularInt::operator%= (const int divisor){
        cur=inRange(cur%divisor);
        return *this;
    }
    bool CircularInt::operator ==(CircularInt const& circularInt){
        if(cur==circularInt.get_cur())return true;
        return false;
    }
    bool CircularInt::operator !=(CircularInt const& circularInt){
        if(cur==circularInt.get_cur())return false;
        return true;
    }
    bool CircularInt::operator> (CircularInt const& circularInt) const{
        if(cur>circularInt.get_cur())return true;
        return false;
    }
    bool CircularInt::operator< (CircularInt const& circularInt) const{
        if(cur<circularInt.get_cur())return true;
        return false;
    }
    bool CircularInt::operator<= (CircularInt const& circularInt) const{
        if(cur<=circularInt.get_cur())return true;
        return false;
    }

    bool CircularInt::operator>= (CircularInt const& circularInt) const{
        if(cur>=circularInt.get_cur())return true;
        return false;
    }
    void CircularInt::operator=(CircularInt const& circularInt){
        this->set_cur(gRange(this->get_start(),this->get_end(),circularInt.get_cur()));
    }
    /*this is uselesss*/
    int  CircularInt::operator+() {
        return this->cur;
    }
    /*Perhaps we can consider start as zero in our system*/
    bool CircularInt::operator!()const{
        if(cur==start)return true;
        else return false;
    }
    bool CircularInt::operator||(const CircularInt& c){
        return (!!*this)||(!!c);

    }
    bool CircularInt::operator&&( const CircularInt& c){
        return (!!*this)&&(!!c);
    }
    int operator/(CircularInt& c,int a){

        for(int i=c.start;i<c.end;i++){
           if((a*i)%c.modulo==c.cur)return i;
          }
        throw string("There is no number x in {" + to_string(c.start)+ "," + to_string(c.end)+ "} such that  x*"+to_string(a)+"=" + to_string(c.cur));
    };
    int CircularInt::operator~(){
        return inRange(~cur);
    }
    int CircularInt::operator&(int a){
        return inRange(cur&a);
    }
    int CircularInt::operator|(int a){
        return inRange(cur|a);
    }
    int CircularInt::operator^(int a){
        return inRange(cur^a);
    }
    int CircularInt::operator<<(int a){
        return inRange(cur<<a);
    }
    int CircularInt::operator>>(int a){
        return inRange(cur>>a);
    }





// Created by ehud on 15/04/18.
//

