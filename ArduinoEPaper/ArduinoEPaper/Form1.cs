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
            serial.PortName = "COM9";
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

            serial.Write(txtMessage.Text + " " + "*");
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

        private void bClear_Click(object sender, EventArgs e)
        {
            txtMessage.Clear();
        }

        private void txtMessage_TextChanged(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            lsTime.Items.Add(tTime.Text);
            lsName.Items.Add(tbName.Text);
        }

        private void bRemove_Click(object sender, EventArgs e)
        {
            //if lsTime.SelectedIndex
            lsName.Items.RemoveAt(lsTime.SelectedIndex);
            lsTime.Items.RemoveAt(lsTime.SelectedIndex);
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            string s = "time|   Name    ____+___________";


            for (int i = 0; i < lsTime.Items.Count; i++)
            {
                s += lsTime.Items[i].ToString().Replace(":","");
                s += "|";
                s += lsName.Items[i].ToString().PadRight(11, ' ') ;

            }
            for (int i = lsTime.Items.Count; i < 6; i++)
            {
                s += "    |           ";
            }

            serial.DtrEnable = true;
            serial.Open();

            serial.Write("$");



            while (true)
            {
                //string s = serial.ReadLine();
                if (serial.ReadLine() == "#\r")
                    break;
            }

            serial.Write(s + "*");

        }
    }
}
