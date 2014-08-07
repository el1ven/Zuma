//
//  main.cpp
//  pro1
//
//  Created by el1ven on 14-6-6.
//  Copyright (c) 2014年 el1ven. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <list>

using namespace std;

list<char> getList(list<char> &l,list<char>::iterator &f_it,list<char>::iterator &b_it){
    //cout<<*f_it<<endl;
    //cout<<*b_it<<endl;
    
    
        while(l.size() != 0 && *f_it == *b_it){
            
            int count1 = 0;
            int count2 = 0;
            int result = 0;
            char y = *f_it;
            
            //cout<<" "<<y<<endl;
            for(; f_it != --l.begin(); f_it--){
                if (*f_it == y) {
                    count1++;
                }else{
                    break;
                }
            }
            
            //if(--f_it == l.begin() && *(l.begin()) == y){
                //count1++;
            //}
            
            for(; b_it != l.end(); b_it++){
                if(*b_it == y){
                    count2++;
                }else{
                    break;
                }
            }
            
            //cout<<count1<<" "<<count2<<endl;
            
            //cout<<*f_it<<endl;
            //cout<<*b_it<<endl;
            
            result = count1 + count2;
            
            if (result >= 3) {
                list<char>::iterator it;
                it = f_it;
                //cout<<"F_it "<<*f_it<<endl;
                it++;
                for (; it != b_it; it++) {
                    l.erase(it);
                }
            }
        }
    
    return l;
    
}


int main(){
    
    list<char> l;//弹道，储存弹珠
    list<char>::iterator it;//遍历指针
    list<char>::iterator f_it;//前方指针front
    list<char>::iterator b_it;//后方指针behind
    
    string str = "";//初始弹珠序列
    int n = 0;//n次操作
    string queue = "";
    string arr[1024];
    
    while(cin>>str){
        for(int i = 0; i < str.length(); i++){
            l.push_back(str[i]);
        }//弹珠放在弹道中
        
        cin>>n;//操作次数
        
        for(int i = 0; i < n; i++){
            
            int loc = 0;//位置
            char x;//输入的弹珠
            it = l.begin();
            queue = "";//存放每次打入弹珠消除之后的结果
            
            cin>>loc>>x;
            
            for(int i = 0; i < loc; i++){
                it++;
            }
            
            l.insert(it,x);
            
            it--;
            f_it = it;
            b_it = it;
            f_it--;
            b_it++;//让三个指针指向插入元素的前，正中，后，三个位置
            
            while(*f_it == *it || *b_it == *it){
                int count1 = 0;
                int count2 = 0;//计算左右两边的连续相同元素个数
                int result = 0;//计算结果
                for(; f_it != --l.begin(); f_it--){
                    if(*f_it == *it){
                        count1++;
                    }else{
                        break;
                    }
                }
                
                //if(--f_it == l.begin() && *(l.begin()) == *it){
                //    count1++;
                //}
                
                for(; b_it != l.end(); b_it++){
                    if(*b_it == *it){
                        count2++;
                    }else{
                        break;
                    }
                }
                
                result = count1 + count2 + 1;
                
                if(result >= 3){
                    list<char>::iterator it2;
                    it2 = f_it;
                    it2++;
                    for(; it2 != b_it; it2++){
                        l.erase(it2);
                    }
                    //cout<<*f_it<<" "<<*b_it<<endl;
                    l = getList(l,f_it,b_it);
                    
                }

                
            }
            
            for(it = l.begin(); it != l.end(); it++){
                queue += *it;
            }
            
            arr[i] = queue;//把每次消除结果都记录下来
        }
        
        for(int j = 0; j < n; j++){
            if(arr[j] == ""){
                cout<<"-"<<endl;
            }else{
                cout<<arr[j]<<endl;
            }
            
        }
        
        l.clear();
        
    }
    
    
    
    
    return 0;
}
























