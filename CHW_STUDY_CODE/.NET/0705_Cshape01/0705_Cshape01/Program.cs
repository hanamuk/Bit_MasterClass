using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace _0705_Cshape01
{
    //싱글톤. 패턴 ---------------------------------------------------
    /*
    //싱글톤 패턴 -----------------------------------------------------------------------------------------
    //리소스를 어마무시하게 쓰는 코드? 프레임워크 같은거에 싱글톤에 사용.
    class Tiger
    {
        private static Tiger Instance = null;

        private Tiger() //private는 객체를 1개도 생성시키지 못하도록..
        {
            WriteLine(1);
        }

        public static Tiger getInstance() //위에서 private로 막아둔 것을 하나라도 사용할 수 있도록하기위해.
        {
            
            if (Instance == null)
            {
                WriteLine(1000);
                Instance = new Tiger();
            }
            return Instance;
           
        }
        int num;
        public int Num { get; set;}

    }
    class Program
    {
        static void Main(string[] args)
        {
            //싱글톤 패턴 : 객체를 1개 이상 만들지 마라.(모르고라도 1개이상 만들어지지 않도록..)
            //이유 : - 1개만 있어도 프로그램에 전혀 문제가 발생하지 않는다.
            //한개이상 만들면 없어도 되는데 리소스가 낭비가 일어난다.

            // 생성자에 private로 만들면 객체를 못만들도록한다.. 그래서 최소한 1개는 사용하도록 할 수 있도록. getinstance를 준다!
            //Tiger t1 = new Tiger();

            Tiger t1 = Tiger.getInstance(); //둘다 동일한객체.
            Tiger t2 = Tiger.getInstance();
            t1.Num = 2000;
            WriteLine(t1.GetHashCode()); //객체 마다 주어진 고유값을 보는 함수.
            WriteLine(t2.GetHashCode());
            WriteLine(t2.Num);

        }
    }
    */

    //상속-------------------------------------------

    /*
    //상속

    //버츄얼은 자식ㅇ ㅣ있으면 자식꺼로 하고, 없으면 내꺼로 한다. --------------------------------------

    class AA
    {
        public void f1()
        {
            WriteLine(1);
        }
        public virtual void f2()
        {
            WriteLine(2);
        }
        public virtual void f3()
        {
            WriteLine(5);
        }

    }
    class BB : AA 
    {
        public void f1()
        {
            WriteLine(3);
        }
        public override void f2()
        {
            WriteLine(4);
        }

    }


    //class CC : AA { }

    class Program
    {
        static void Main(string[] args)
        {

            //BB t1 = new BB();
            //t1.f1();
            //t1.f2();

            //AA t2 = new BB();
            //t2.f1();
            //t2.f2();


            //AA t1 = new BB();
            //WriteLine(t1.GetHashCode());
            ////셋다 서로 다른객체
            //t1 = new CC();
            //WriteLine(t1.GetHashCode());
            //t1 = new BB();
            //WriteLine(t1.GetHashCode());
           

          
            //AA t1 = new AA();
            //BB t2 = new BB();
            //AA t3 = new BB();  // 부모 = new 자식(); 부자가 들어오면 업케스팅이다. , 업케스팅이 안되면 다형성이 안된다.
            //                    // 문법(클래스의정의?)은 A의 문법만 사용하고 = new BB는 메모리는 A,B를 다 잡는다(이유는 B가 A를 상속했기 떄문에 둘다 할당함.)
            //                    // 메모리는 A,B 다받아놓고, A문법만 쓸거면 왜 둘다 메모리를 잡느냐? >> 

            ////BB t3 = new AA();//다운캐스팅, C#에서는 안됨.
            

        }
    }
    */

    //다형성---------------------------------------------
    /*
    //다형성 프로그래밍. 사용하는거에 따라 다르게 형성된다.
    //개방 폐쇄 원칙: 클래스를 수정하지않고 사용하는것.
    class Animal
    {
        public virtual void cry()
        {
            WriteLine("울음이 없다.");
        }
    }
    class Dog : Animal
    {
        public override void cry()
        {
            WriteLine("멍멍");

        }
    }
    class Cat : Animal
    {
        public override void cry()
        {
            WriteLine("야옹");
        }

    }

    class Snake : Animal
    {
        

    }
    class Zoo
    {

        //업캐스팅을 사용하는 이유. ! 같은 클래스를 상속받을 떄 부모의 것으로 인자를 받아서 사용하면 자식이 함수를 재정의 했다면 자식의 것을 사용하기 떄문에.
        //Animal Animal = new Dog();
        //Animal Animal = new Cat();
        public void sound(Animal Animal)
        {
            Animal.cry();
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Zoo zoo = new Zoo();
            zoo.sound(new Dog());
            zoo.sound(new Cat());
            zoo.sound(new Snake());

        }
    }

    */


    // 데이코레이션 패턴 (값을 감싸고 또 그클래스를 감싸고 감싸고......)---------------------------------- 
    //커피를 먹는데 프림을 추가하고, 설탕을 추가하고,.. 는 맘대로니까 무언가를 추가하는데 잘 모르는 경우? 같은느낌에서 사용
    /*
    class A
    {
        int num = 30;
        public virtual int run()
        {
            WriteLine("A Run");
            return num;
        }
    
    }
    class B: A
    {

        int num = 20;
        A a;
        public B(A a) 
        {
            this.a = a;
        }

        public override int run()
        {
            WriteLine("b Run");
            return num + a.run();
        }

    }


    class C : A
    {

        int num = 10;
        A a;
        public C(A a)
        {
            this.a = a;
        }

        public override int run()
        {
            WriteLine("C Run");
            return num + a.run();
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            A a = new A();
            //a.run();
            a = new B(a);
            //WriteLine(a.run());
            a = new C(a);
            WriteLine(a.run());
        }
    }
    */


    // 데이코레이션 패턴 예시
    /*
    class 커피
    {
        int num = 30;
        public virtual int 가격()
        {
            WriteLine("커피 주문");
            return num;
        }

    }
    class 설탕 : 커피
    {

        int num = 20;
        커피 a;
        public 설탕(커피 a)
        {
            this.a = a;
        }

        public override int 가격()
        {
            WriteLine("설탕 추가");
            return num + a.가격();
        }

    }


    class 프림 : 커피
    {

        int num = 10;
        커피 a;
        public 프림(커피 a)
        {
            this.a = a;
        }

        public override int 가격()
        {
            WriteLine("프림 추가");
            return num + a.가격();
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            커피 a = new 커피();
            //a.run();
            a = new 설탕(a);//설탕추가
            a = new 프림(a);//나는 프림을 추가하고싶다. 프림도 가격도 추가
            a = new 프림(a);//나는 프림을 추가하고싶다. 프림 두번 추가.
            WriteLine(a.가격());
        }
    }

     */



    //다형성, 오버라이드 예시, 개방 폐쇠의 원칙, 전략패턴?--------------------------------------------
    /*
    class Baduk //AI클래스와 Baduk은 의존관계라고 한다. 
    {
        AI ai;
        public Baduk(AI ai)
        {
            this.ai = ai;   //이렇게 해주는 것을 객체 주입? 이라고 한다. ..전략패턴? -----------------------------------------------------------
            WriteLine("대국을 시작합니다");
        }

        //인수 전달안해도 똑같으면 인수전달을 굳이 써야하나?
        public void play() { ai.play();  }
        public void stop() { ai.stop(); }
    }

    //abstract class AI 얘는 인터페이스로 만드는 게 맞음. 
    // {
    //     public abstract void play();  //abstract추상: 미완성(해석의 결과가 나지 않은것..전부 다르게 해석..), 상속을 받은 클래스는 반드시 구현해야한다.
    //추상함수를 가진 클래스는 반드시 추상클래스 이어야한다.
    //}

    interface AI
    {
        void play();
        void stop();
    }

    class AlphaGo : AI
    {
        public void play()
        {
            WriteLine("인공지능은 알파고 입니다");
        }
        public void stop()
        {
            WriteLine("알파고가 점수를 계산합니다.");
        }
    }

    class BetaGo : AI
    {
        public void play()
        {
            WriteLine("인공지능은 베타고 입니다");
        }

        public void stop()
        {
            WriteLine("베타고가 점수를 계산합니다.");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Baduk baduk1 = new Baduk(new AlphaGo());
            baduk1.play();
            baduk1.stop();

            Baduk baduk2 = new Baduk(new BetaGo());
            baduk2.play();
            baduk2.stop();
        }
    }
    */


    //this 사용처------------------------------------------------------------

    //this 용법 1------------------------------------------------------------
    /*
    //ex1
    class Tiger
    { 
        Tiger this;
        Tiger()
        {
                this = tiger;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Tiger tiger = new Tiger();
        }
    }

    //ex2) 
    class Tiger
    {
        int num;
        public Tiger()
        {

            WriteLine(this.GetHashCode();
        }
       
    }
    class Program
    {
        static void Main(string[] args)
        {
            Tiger tiger = new Tiger();
            WriteLine(tiger.GetHashCode());
        }
    }

    //ex3) 
    class Tiger
    {
        int num;
        public Tiger(int num)
        {
            this.num = num;
        }
        void m1(int num)
        {
            this.num = num * 3;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Tiger tiger = new Tiger();
            tiger.m1(10);
        }
    }
    */

    //this 용법 2 chainning------------------------------------
    /*
    class Tiger
    {
        public Tiger m1()
        {
            return new Tiger();
        }
        public Tiger m2()
        {
            WriteLine("1");
            return this;
        }
        public Tiger m3()
        {
            WriteLine("2");
            return this;
        }
        public void m4()
        {
            WriteLine("3");
            
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Tiger tiger = new Tiger();
            Tiger t = tiger.m2();
            tiger.m2().m2().m2();       //함수 체인링....함수 호출 중간에 엉뚱한 코드가 들어오는것을 방지하기 위해 사용한다.
            WriteLine("-----------------");

            Tiger t1 = tiger.m2();
            t1.m2().m3().m3().m2().m4();

        }
    }
    */


    //this 용법 3 . 너에게로 나를 보낸다 문법..-------------------------------------
    class Tiger //나 
    {
        public int money=100;
        public int shape=20;

        public void m1()
        {
            WriteLine(1);
            Lion lion = new Lion();
            //lion.m2(new Tiger())
            lion.결혼해줘(this);
        }
      
    }
    class Lion  //너
    {
        public void 결혼해줘(Tiger t)
        {
            WriteLine(t.money+ t.shape);
            if (t.money >= 20)
            {
                WriteLine("ok");
            }
            else
                WriteLine("no");

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Tiger tiger = new Tiger();
            tiger.m1();
        }
    }
}
