#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct ThiSinh
{
    string id;
    string hoVaTen;
    float toan = 0, ly = 0, hoa = 0, sinh = 0,
          van = 0, su = 0, dia = 0, GDCD = 0,
          ngoaiNgu = 0,
          KHTN = 0, KHXH = 0;
    string ghiChu;
    string tinhr;
    float tongDiem = 0;
};
ThiSinh docThongTinThiSinh(string line)
{
    //So bao danh, Ho va ten, Toan, Ngu Van, Vat Ly, Hoa Hoc, Sinh Hoc, Lich Su, Dia Ly, GDCD, KHTN, KHXH, Ngoai Ngu, Ghi Chu, Tinh
    size_t pos = 0;
    size_t nextPos = line.find(',');
    ThiSinh thiSinh;
    //So bao danh
    string temp = line.substr(pos, nextPos - pos);
    thiSinh.id = temp;

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    thiSinh.hoVaTen = temp;

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.toan = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.van = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.ly = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.hoa = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.sinh = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.su = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.dia = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.GDCD = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.KHTN = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.KHXH = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    if (temp != "")
        thiSinh.ngoaiNgu = std::stof(temp);

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    thiSinh.ghiChu = temp;

    pos = nextPos + 1;
    nextPos = line.find(',', pos);
    temp = line.substr(pos, nextPos - pos);
    thiSinh.tinhr = temp;

    return thiSinh;
}
vector<ThiSinh> docDanhSachThiSinh(char *tenFile)
{
    vector<ThiSinh> danhSach(0);
    ifstream fin(tenFile);
    if (fin.is_open())
    {
        string temp;
        getline(fin, temp);
        while (fin.eof() == false)
        {
            getline(fin, temp);
            danhSach.push_back(docThongTinThiSinh(temp));
        }
        fin.close();
    }
    return danhSach;
}

string daoHoVaTen(const string &s)
{
    string res = "";
    size_t pos = 0;
    size_t nextPos = s.find(' ', pos);
    res = s.substr(pos, nextPos - pos);
    pos = nextPos + 1;
    nextPos = s.find(' ', pos);
    while (nextPos != string::npos)
    {
        res = s.substr(pos, nextPos - pos) + ' ' + res;
        pos = nextPos + 1;
        nextPos = s.find(' ', pos);
    }
    nextPos = s.length();
    res = s.substr(pos, nextPos - pos) + ' ' + res;
    return res;
}

void daoNguocTenThiSinh(vector<ThiSinh> &danhSachThiSinh)
{
    for (auto &ts : danhSachThiSinh)
    {
        ts.hoVaTen = daoHoVaTen(ts.hoVaTen);
    }
}

void vietHoaHoVaTen(string &s)
{
    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] = s[0] + 'A' - 'a';
    size_t pos = s.find(' ');
    while (pos != string::npos)
    {
        pos++;
        if (s[pos] >= 'a' && s[pos] <= 'z')
            s[pos] = s[pos] + 'A' - 'a';
        pos = s.find(' ', pos);
    }
}

void vietHoaTenThiSinh(vector<ThiSinh> &danhSachThiSinh)
{
    for (auto &ts : danhSachThiSinh)
    {
        vietHoaHoVaTen(ts.hoVaTen);
    }
}
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
void doiTenThiSinh(vector<ThiSinh> &danhSachThiSinh)
{
    for (size_t i = 0; i < danhSachThiSinh.size(); i++)
    {
        for (size_t j = 0; j < danhSachThiSinh.size(); j++)
        {
            if (danhSachThiSinh[i].id == "BD1200001" && danhSachThiSinh[j].id == "BD1200003")
            {
                swap(danhSachThiSinh[i].hoVaTen, danhSachThiSinh[j].hoVaTen);
            }
            if (danhSachThiSinh[i].id == "BD1200005" && danhSachThiSinh[j].id == "BD1200002")
            {
                swap(danhSachThiSinh[i].hoVaTen, danhSachThiSinh[j].hoVaTen);
            }
        }
    }
}
void tinhDiemKHTN(ThiSinh &t)
{
    t.KHTN = t.ly + t.hoa + t.sinh;
}
void tinhDiemKHXH(ThiSinh &t)
{
    t.KHXH = t.su + t.dia + t.GDCD;
}
void tinhDiemTong(ThiSinh &t)
{
    tinhDiemKHTN(t);
    tinhDiemKHXH(t);
    t.tongDiem = t.toan + t.van + t.ngoaiNgu + t.KHTN + t.KHXH;
}
void tinhDiem(vector<ThiSinh> &danhSachThiSinh)
{
    for (auto &ts : danhSachThiSinh)
    {
        tinhDiemTong(ts);
    }
}
void xuatFile(const vector<ThiSinh> &danhSachThiSinh, char *tenFile)
{
    ofstream ofFile(tenFile);
    if (ofFile.is_open())
    {
        ofFile << "TONG KET"
               << "\n\n";
        for (size_t i = 0; i < danhSachThiSinh.size(); i++)
        {
            ofFile << danhSachThiSinh[i].id << '\n';
            ofFile << danhSachThiSinh[i].hoVaTen << '\n';
            ofFile << "Diem thi khoi khoa hoc tu nhien: " << danhSachThiSinh[i].KHTN << '\n';
            ofFile << "Diem thi khoi khoa hoc xa hoi: " << danhSachThiSinh[i].KHXH << '\n';
            ofFile << "Diem tong: " << danhSachThiSinh[i].tongDiem << '\n';
            ofFile << '\n';
        }
        ofFile.close();
    }
}

int main()
{
    // ThiSinh t = docThongTinThiSinh("BD1200013,minh Bao le,2.8,5.0,,,,2.75,,,,,,,BinhDinh");
    char tenFile[] = "data.txt\0";
    char tenFileXuat[] = "tongketdiemthi.txt";
    vector<ThiSinh> danhsach = docDanhSachThiSinh(tenFile);
    daoNguocTenThiSinh(danhsach);
    vietHoaTenThiSinh(danhsach);
    doiTenThiSinh(danhsach);
    tinhDiem(danhsach);
    xuatFile(danhsach, tenFileXuat);
    return 0;
}