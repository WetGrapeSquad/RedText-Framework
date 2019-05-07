#pragma once

namespace rt {
	template <typename type>
	class Rvector
	{
	public:
        Rvector() {
            this->lengh = -1;
            this->vect = new type[1];
		}
        Rvector(const Rvector& vect) {
            if(vect.lengh == -1){
                this->lengh = -1;
                delete [] this->vect;
                this->vect = new type[1];
            }
            this->lengh = vect.lengh;
            this->vect = new type[this->lengh + 1];
            for(int i = 0; i <= this->lengh; i++) {
                this->vect[i] = vect.vect[i];
            }
            return;
        }
        ~Rvector(){
            delete [] this->vect;
        }
        void pop_back() {
            if(this->lengh == -1) return;
            if(this->lengh == 0){
                this->lengh--;
                return;
            }
            type *h = this->vect;
            this->vect = new type[this->lengh];
            this->lengh--;
            for(int i = 0; i <= this->lengh; i++){
                this->vect[i] = h[i];
            }
            delete [] h;
            return;
		}
        void pop(int i) {
            if(this->lengh == -1) return;
            if(this->lengh == 0){
                this->lengh--;
                return;
            }
            if(i < 0) i = 0;
            if(i > this->lengh) i = this->lengh;
            type *h = this->vect;
            this->vect = new type[this->lengh];
            int f = 0;
            for(f = 0; f < i; f++){
                this->vect[f] = h[f];
            }
            f++;
            for(; f <= this->lengh; f++){
                this->vect[f - 1] = h[f];
            }
            this->lengh--;
            delete [] h;

		}
        void push_back() {
            if(this->lengh == -1){
                this->lengh++;
                return;
            }
            type *h = this->vect;
            this->lengh++;
            this->vect = new type[this->lengh + 1];
            for(int i = 0; i < this->lengh; i++) {
                this->vect[i] = h[i];
            }
            delete [] h;
            return;
		}
        void push_back(type el) {
            if(this->lengh == -1){
                this->lengh++;
                this->vect[0] = el;
                return;
            }
            type *h = this->vect;
            this->lengh++;
            this->vect = new type[this->lengh + 1];
            for(int i = 0; i < this->lengh; i++) {
                this->vect[i] = h[i];
            }
            delete [] h;
            this->vect[this->lengh] = el;
            return;
		}
        void setSize(int s){
            delete [] this->vect;
            this->lengh = s;
            this->vect = new type[this->lengh + 1];
            return;
        }
        operator type*(){
            return this->vect;
        }
        type* get(){return vect;}
        void setClear(){
            delete [] this->vect;
            this->vect = new type[1];
            this->lengh = -1;
        }
        void switchElement(int f, int l) {
            type t = this->vect[l];
            this->vect[l] = this->vect[f];
            this->vect[f] = t;
            return;
		}
        type& operator[](int i) {
            return this->vect[i];
		}
        int size() {
            return this->lengh;
		}
	private:
		type *vect;
		int lengh;
	};
}
