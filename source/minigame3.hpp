#ifndef MINIGAME3_HPP
#define MINIGAME3_HPP
class Fly{
    private:
        int x = 112;
        int y = 50;
        double speed = 0.5;
        int acc_y = -15;
        bool stuck = false;
    public:
        double t = 0;
        Fly(){
            NF_CreateSprite(1, 12, 2, 2, x, y);
        };
        void Check(){
            t = t/60;
            y += acc_y*speed;
            acc_y += 1;
            if(KEY_TOUCH & keysDown()){
                acc_y = -10;
            }
            if(y >= ground_y){
                win = -2;
                stuck = true;
            }
            if(stuck == false){
                NF_MoveSprite(1, 12, x, y);
            }
        };
        void End(){
            NF_DeleteSprite(1, 12);
        }
};
class Tuyo{
    private:
        int x;
        int y;
        int ids;
    public:
        Tuyo(int id, int start, int height){
            y = height;
            x = start;
            ids = id;
            NF_CreateSprite(1, id, 4, 4, x, y);
        }
        void Check(){
            x -= 3;
            NF_MoveSprite(1, ids, x, y);

        }
        void End(){
            NF_DeleteSprite(1, ids);
        }
};
#endif