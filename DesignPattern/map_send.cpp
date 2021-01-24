/*
 * @Author: your name
 * @Date: 2021-01-24 10:51:52
 * @LastEditTime: 2021-01-24 15:06:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \npb\DesignPattern\map_send.cpp
 */

#include <iostream>
#include <memory>

using namespace std;

class Transfer
{
private:
    
public:
    virtual bool UploadBuffer(std::string &content) = 0;
    virtual bool UploadFile(std::string file) = 0;
};


class S3 : public Transfer
{
public:
    bool UploadBuffer(std::string &content) {
        std::cout << "S3 UploadBuffer : " << content <<  std::endl;
        return true;
    }
     
    bool UploadFile(std::string file) {
        std::cout << "S3 UploadFile " << std::endl;
        return true;
    }

    S3() {}
    ~S3(){}
    
private:
    
};

class FDS : public Transfer
{
public:
    bool UploadBuffer(std::string &content) {
        std::cout << "FDS UploadBuffer : " << content <<  std::endl;
        return true;
    }

    bool UploadFile(std::string file) {
        std::cout << "FDS UploadFile " << std::endl;
        return true;
    }

    FDS() {}
    ~FDS(){}
    
private:
    
};


class MapSend
{
private:
    std::unique_ptr<Transfer> Send;
     
public:
    MapSend(Transfer *send) {
        if (send == nullptr) {
            std::cerr << "MapSend construction error " << std::endl;
            exit(-1);
        } else {
            Send = std::unique_ptr<Transfer>(send);
        } 
    }

    void UploadMap() {
        std::string buffer{"MapSend ----------------"};
        Send->UploadBuffer(buffer);
    }

    void ChangeMethod(Transfer *send) {
        if (send == nullptr) {
            std::cerr << "ChangeMethod error " << std::endl;
        } else {
            Send = std::unique_ptr<Transfer>(send);
        } 
    }
    
    ~MapSend(){}
};

class CleanRecord  
{
private:
    std::unique_ptr<Transfer> Send;
    
public:
    CleanRecord(Transfer *send) {
        if (send == nullptr) {
            std::cerr << "MapSend construction error " << std::endl;
            exit(-1);
        } else {
            Send = std::unique_ptr<Transfer>(send);
        } 
    }

    void UploadCleanRecord() {
        Send->UploadFile("buffer");
    }

    void ChangeMethod(Transfer *send) {
        if (send == nullptr) {
            std::cerr << "ChangeMethod error " << std::endl;
        } else {
            Send = std::unique_ptr<Transfer>(send);
        } 
    }

    ~CleanRecord(){}
};


 
int main()
{
    S3 *mS3 = new S3();
    MapSend mMapSend(mS3);
    CleanRecord mCleanRecord(mS3);

    mMapSend.UploadMap();
    mCleanRecord.UploadCleanRecord();

//-----------------------------------
    FDS *mFds = new FDS();
    // MapSend mMapSendFds(mFds);
    // CleanRecord mCleanRecordFds(mFds);
    mMapSend.ChangeMethod(mFds);
    mCleanRecord.ChangeMethod(mFds);

    mMapSend.UploadMap();
    mCleanRecord.UploadCleanRecord();

    // mMapSendFds.UploadMap();
    // mCleanRecordFds.UploadCleanRecord();

    delete mS3;
    delete mFds;
    
    return 0;
}


// class IReader
// { 
// public:
//     virtual string getContents() = 0;
// };

// class Book :public IReader
// {
// public:
//     string getContents() {
//         return "从前有座山， 山里有座庙， 庙里有个小和尚， 要听故事";
//     }
// };
// class NewsPaper:public IReader
// { 
//     public:
//     string getContents() {
//         return "Trump， 赢得的下一届美国总统大选";
//     }
// };

// class Mother
// { 
//     public:
//     // void tellStroy(IReader *i) {
//     void tellStroy(std::shared_ptr<IReader>(i)) {
        
//         cout<<i->getContents()<<endl;
//     }
// };

// int main()
// {
//     Mother m;
//     // Book *b = new Book;
//     // NewsPaper *n = new NewsPaper;

//     std::shared_ptr<Book> b = std::shared_ptr<Book>(new Book());
//     std::shared_ptr<NewsPaper> n = std::shared_ptr<NewsPaper>(new NewsPaper());

//     cout<<"Mother start to tell story"<<endl;
//     m.tellStroy(b);
//     cout<<"Mother start to tell news"<<endl;
//     m.tellStroy(n);
//     // delete b;
//     // delete n;
//     return 0;
// }