using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ArduinoEPaper
{
    public partial class fMain : Form
    {
        public fMain()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serial.PortName = "COM40";
            serial.BaudRate = 9600;


        }
        private void test(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            Console.WriteLine(serial.ReadLine());
        }

        private void bSend_Click(object sender, EventArgs e)
        {
            serial.DtrEnable = true;
            serial.Open();

            serial.Write("$");



            while (true)
            {
                //string s = serial.ReadLine();
                if (serial.ReadLine() == "#\r")
                    break;
            }

            serial.Write(txtMessage.Text + "*");
            //char[] x = {'x'};
            //int i = serial.Read(x,0,1);
            //while (true)
            //{
            //    string s = serial.ReadExisting();
            //    int i = serial.ReadByte()
            //    Console.WriteLine("Read: " + s + i );
            //}
                //    if (s=="#")
            //        break;
            //}
            //serial.Write(txtMessage.Text + "*");
            //while (serial.available() > 0)
            //{
            //    ch = serial.read();
            //    if (ch == '#')  // if recieve reply start senting data
            //    {
            //        serial.Write(txtMessage.Text + "*");
            //    }
            //}
           

            serial.Close();
        }
    }
}
