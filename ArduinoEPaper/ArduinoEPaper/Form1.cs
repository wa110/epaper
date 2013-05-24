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
            serial.PortName = "COM12";
            serial.BaudRate = 9600;


        }

        private void bSend_Click(object sender, EventArgs e)
        {
            serial.Open();
            serial.Write(txtMessage.Text + "*");
            serial.Close();
        }
    }
}
