#include "CircularInt.hpp"
/*
 * was inspired regarding operators i had missing from @Orel Shalom and @Samuel Bismuth
 */
    // helper function
    int  gRange(int start,int end,int cur){
        int modulo=end-start+1;
        cur=cur%modulo;
        if(cur<0)cur=cur+modulo;
        for(int i = start ; i <= end ; i++ ){
            if(i%modulo==cur){
                return i;
            }
        }
    }
    int CircularInt::inRange(int result){
     result=result%modulo;
     if(result<0)result=result+modulo;
     for (int i = start; i <=end ; i++) {
        if(i%modulo==result){
            return i;
          }
     } return result;
    }
    // builder
    CircularInt::CircularInt(int start_point,int end_point){
        start=start_point;
        end=end_point;
        cur=start_point;
        modulo=end-start+1;

    };
    //getters and setters:
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


    //some fucking operators
    void CircularInt::operator= (CircularInt circularInt){
        this->set_cur(circularInt.get_cur());
    }
    void CircularInt::operator= (int a){
        this->set_cur( a );

    }
    CircularInt CircularInt::operator+ (const CircularInt circularInt){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        temp->set_cur(get_cur()+circularInt.get_cur());
        return *temp;

    }
    CircularInt CircularInt::operator+ (const int a){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        temp->set_cur(get_cur()+a);
        return *temp;

    }
    CircularInt CircularInt::operator- (const CircularInt circularInt){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        temp->set_cur(this->get_cur()-circularInt.get_cur());
        return *temp;
    }
    CircularInt CircularInt::operator- (const int a){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        temp->set_cur(this->get_cur()-a);
        return *temp;
    }
    CircularInt CircularInt::operator+ (){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        temp->cur=get_cur();
        return *temp;
    }
    CircularInt CircularInt::operator- (){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        temp->set_cur(get_end()-get_cur());
        return *temp;
    }
    CircularInt CircularInt::operator* (const CircularInt circularInt){
        CircularInt *temp= new CircularInt(get_start(),get_end());
        temp->set_cur(get_cur()*circularInt.get_cur());
        return *temp;
    }

    CircularInt CircularInt::operator* (const int a){
        CircularInt *temp= new CircularInt(get_start(),get_end());
        temp->set_cur(get_cur()*a);
        return *temp;
    }
    CircularInt CircularInt::operator/ (const CircularInt circularInt){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        if(this->get_cur()%circularInt.get_cur()!=0||circularInt.get_cur()==0)throw string("division error");
        temp->set_cur(this->get_cur()/circularInt.get_cur());
        return *temp;
    }
    CircularInt CircularInt::operator/ (const int a){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        if(this->get_cur()%a!=0||a==0)throw string("division error");
        temp->set_cur(this->get_cur()/a);
        return *temp;
    }
    CircularInt CircularInt::operator% (const CircularInt circularInt){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        if(circularInt.get_cur()==0)throw string("division error");
        temp->set_cur(this->get_cur()%circularInt.get_cur());
        return *temp;
    }
    CircularInt CircularInt::operator% (const int a){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        if(a==0)throw string("division error");
        temp->set_cur(this->get_cur()%a);
        return *temp;
    }
    CircularInt& CircularInt::operator++ () {
    cur++;
    set_cur(cur);
    return *this;
    }
    CircularInt CircularInt::operator++ ( int a){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        int temps=get_cur();
        temp->set_cur(++temps);
        set_cur(temps++);
        return *temp;
    }
    CircularInt& CircularInt::operator-- (){
        set_cur((get_cur()-1));
        return *this;
    }
    CircularInt CircularInt::operator-- (const int a){
        CircularInt *temp= new CircularInt(this->get_start(),this->get_end());
        temp->set_cur(get_cur()-1);
        return *temp;
    }



    bool CircularInt::operator== (const CircularInt& circularInt){
        if(this->get_cur()==circularInt.get_cur()&&
                this->get_start()==circularInt.get_start()&&
                this->get_end()==circularInt.get_end())return true;
        return false;
    }
    bool CircularInt::operator== (const int& a){
        if (this->get_cur()==a)return true;
        return false;
    }
    bool CircularInt::operator!= (const CircularInt& circularInt){
        if(this->get_cur()==circularInt.get_cur()&&
           this->get_start()==circularInt.get_start()&&
           this->get_end()==circularInt.get_end())return false;
        return true;
    }
    bool CircularInt::operator!= (const int& a){
        if (this->get_cur()==a)return false;
        return true;
    }
    bool CircularInt::operator> (const CircularInt& circularInt) const{
        if(this->get_cur()>circularInt.get_cur())return true;
        return false;
    }
    bool CircularInt::operator> (const int& a) const{
        if (this->get_cur()>a)return true;
        return false;
    }

    bool CircularInt::operator< (const CircularInt& circularInt) const{
        if (this->get_cur()<circularInt.get_cur())return true;
        return false;
    }
    bool CircularInt::operator< (const int& a) const{
        if (this->get_cur()<a)return true;
        return false;
    }
    bool CircularInt::operator>= (const CircularInt& circularInt) const{
        if(get_cur()>=circularInt.get_cur())return true;
        return false;
    }
    bool CircularInt::operator>= (const int& a) const{
        if(get_cur()>=a)return true;
        return false;
    }
    bool CircularInt:: operator<= (const CircularInt& circularInt) const{
        if(get_cur()<=circularInt.get_cur())return true;
        return false;
    }
    bool CircularInt::operator<= (const int& a) const{
        if(get_cur()<=a)return true;
        return false;
    }




     int operator-( int a,CircularInt& c)  {
        int modulo=(c.get_end()-c.get_start()+1);
         a=a-c.get_cur();
         while(a<0){
             a=a+modulo;
         }
         a=a%modulo;
         for(int i=c.get_start();i<=c.get_end();i++){
             if(i%modulo==a){
                 return i;
             }
         }
    }



    bool CircularInt::operator! () const{
        return !(this->get_cur());
    }
    bool CircularInt::operator&& (const CircularInt circularInt){
        return (this->get_cur()&&circularInt.get_cur());
    }
    bool CircularInt::operator&& (const int a){
        return (this->get_cur()&&a);
    }
    bool CircularInt::operator|| (const CircularInt circularInt){
        return (this->get_cur()||circularInt.get_cur());
    }

    bool CircularInt::operator|| (const int a){
        return (this->get_cur()||a);

    }


    CircularInt CircularInt::operator~ (){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur(~get_cur());
        return *temp;
    }
    CircularInt CircularInt::operator& (const CircularInt circularInt){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())&(circularInt.get_cur()));
        return *temp;
    }
    CircularInt CircularInt::operator& (const int a){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())&(a));
        return *temp;
    }
    CircularInt CircularInt::operator| (const CircularInt circularInt){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())|(circularInt.get_cur()));
        return *temp;
    }
    CircularInt CircularInt::operator| (const int a){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())|(a));
        return *temp;
    }

    CircularInt CircularInt::operator^ (const CircularInt circularInt){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())^(circularInt.get_cur()));
        return *temp;
    }
    CircularInt CircularInt::operator^ (const int a){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())^(a));
        return *temp;
    }
    CircularInt CircularInt::operator<< (const CircularInt circularInt){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())<<(circularInt.get_cur()));
        return *temp;
    }
    CircularInt CircularInt::operator<< (const int a){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())<<(a));
        return *temp;
    }
    CircularInt CircularInt::operator>> (const CircularInt circularInt){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())>>(circularInt.get_cur()));
        return *temp;
    }
    CircularInt CircularInt::operator>> (const int a){
        CircularInt *temp=new CircularInt (get_start(),get_end());
        temp->set_cur((get_cur())>>(a));
        return *temp;
    }




    CircularInt& CircularInt::operator+= (const CircularInt circularInt){
        this->set_cur(get_cur()+circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator+= (const int a){
        this->set_cur(get_cur()+a);
        return *this;
    }
    CircularInt& CircularInt::operator-= (const CircularInt circularInt){
        this->set_cur(get_cur()-circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator-= (const int a){
        this->set_cur(get_cur()-a);
        return *this;
    }
    CircularInt& CircularInt::operator*= (const CircularInt circularInt){
        int temp=get_cur()*circularInt.get_cur();
        set_cur(temp);
        return *this;
    }
    CircularInt& CircularInt::operator*= (const int a){
        int temp=get_cur()*a;
        set_cur(temp);
        return *this;
    }
    CircularInt& CircularInt::operator/= (const CircularInt circularInt){
        if(circularInt.get_cur()==0||get_cur()%circularInt.get_cur()!=0)throw string("division error");
        this->set_cur(get_cur()/circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator/= (const int a){
        if(a==0||get_cur()%a!=0)throw string("division error");
        this->set_cur(get_cur()/a);
        return *this;
    }
    CircularInt& CircularInt::operator%= (const CircularInt circularInt){
        if(circularInt.get_cur()==0)throw string("division error");
        this->set_cur(get_cur()%circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator%= (const int a){
        if(a==0)throw string("division error");
        this->set_cur(get_cur()%a);
        return *this;
    }
    CircularInt& CircularInt::operator&= (const CircularInt circularInt){
        set_cur(get_cur()&circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator&= (const int a){
        set_cur(get_cur()&a);
        return *this;
    }
    CircularInt& CircularInt::operator|= (const CircularInt circularInt){
        set_cur(get_cur()|circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator|= (const int a){
        set_cur(get_cur()|a);
        return *this;
    }

    CircularInt& CircularInt::operator^= (const CircularInt circularInt){
        set_cur(get_cur()^circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator^= (const int a){
        set_cur(get_cur()^a);
        return *this;
    }
    CircularInt& CircularInt::operator<<= (const CircularInt circularInt){
        set_cur(get_cur()<<circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator<<= (const int a){
        set_cur(get_cur()<<a);
        return *this;
    }
    CircularInt& CircularInt::operator>>= (const CircularInt circularInt){
        set_cur(get_cur()>>circularInt.get_cur());
        return *this;
    }
    CircularInt& CircularInt::operator>>= (const int a){
        set_cur(get_cur()>>a);
        return *this;
    }


     CircularInt operator+ (const int a, const CircularInt& circularInt){
         CircularInt *temp=new CircularInt (circularInt.get_start(),circularInt.get_end());
         temp->set_cur(circularInt.get_cur()+a);
         return *temp;
     }
     CircularInt operator- (const int a, const CircularInt& circularInt){
         CircularInt *temp=new CircularInt (circularInt.get_start(),circularInt.get_end());
         temp->set_cur(a-circularInt.get_cur());
         return *temp;
     }
     CircularInt operator/ (const int a, const CircularInt& circularInt){
         CircularInt *temp=new CircularInt (circularInt.get_start(),circularInt.get_end());
         if(circularInt.get_cur()==0||a%circularInt.get_cur()!=0)throw string("division error");
         temp->set_cur(a/circularInt.get_cur());
         return *temp;
     }
     bool operator== (const int& a, const CircularInt& circularInt){
         if(a==circularInt.get_cur())return true;
         return false;
     }

     bool operator!= (const int& a, const CircularInt& circularInt){
         if(a!=circularInt.get_cur())return true;
         return false;
     }

     bool operator> (const int& a, const CircularInt& circularInt){
         if(a>circularInt.get_cur())return true;
         return false;
     }
     bool operator< (const int& a, const CircularInt& circularInt){
         if(a<circularInt.get_cur())return true;
         return false;
     }
     bool operator>= (const int& a, const CircularInt& circularInt){
         if(a>=circularInt.get_cur())return true;
         return false;
     }
     bool operator<= (const int& a, const CircularInt& circularInt){
         if(a<=circularInt.get_cur())return true;
         return false;
     }

     istream& operator>> (istream& is, CircularInt& circularInt){
         int x;
         is>> x;
         circularInt.set_cur(x);
     }

    ostream& operator<<(ostream& output,const CircularInt& x){
    output<<x.cur;
        return  output;
    }





// Created by ehud on 15/04/18.
//

