v1[0].push_back(make_pair(1,1));
    for(int i=1; pow(2,i)<=n; i++){
        int now = pow(2,i);
        int total = now*now;
        int qt = total / 4;
        for(int j=0; j<4; j++){
            if(j == 0){//1번째
                for(int k=0; k<qt; k++){
                    int x, y;
                    x = v1[i-1].at(qt-k-1).second;
                    y = (now/2) - v1[i-1].at(qt-k-1).first + 1;
                    v1[i].push_back(make_pair(x,y));
                }
            }
            else if(j == 1){//2번째
                for(int k=0; k<qt; k++){
                    int x, y;
                    x = v1[i-1].at(k).first;
                    y = v1[i-1].at(k).second + (now/2);
                    v1[i].push_back(make_pair(x,y));
                }
            }
            else if(j == 2){//3번째
                for(int k=0; k<qt; k++){
                    int x, y;
                    x = v1[i-1].at(k).first + (now/2);
                    y = v1[i-1].at(k).second + (now/2);
                    v1[i].push_back(make_pair(x,y));
                }
            }
            else{//4번째
                for(int k=0; k<qt; k++){
                    int x, y;
                    x = (now/2) - v1[i-1].at(qt-k-1).second + 1 + (now/2);
                    y = v1[i-1].at(qt-k-1).first;
                    v1[i].push_back(make_pair(x,y));
                }
            }
        }
    }
    for(int i=0; i<=15; i++){
        if(pow(2,i) == n){
            cout << v1[i].at(m-1).first << " " << v1[i].at(m-1).second;
            break;
        }
    }