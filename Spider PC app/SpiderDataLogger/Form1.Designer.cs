namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.serialComboBox = new System.Windows.Forms.ComboBox();
            this.labelSerialPort = new System.Windows.Forms.Label();
            this.openButton = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.textBoxDebug = new System.Windows.Forms.TextBox();
            this.labelDebug = new System.Windows.Forms.Label();
            this.buttonClearDebug = new System.Windows.Forms.Button();
            this.textBoxWarnings = new System.Windows.Forms.TextBox();
            this.groupBoxWarnings = new System.Windows.Forms.GroupBox();
            this.groupBoxCRC = new System.Windows.Forms.GroupBox();
            this.buttonResetCounters = new System.Windows.Forms.Button();
            this.labelEscCharFailsVal = new System.Windows.Forms.Label();
            this.labelCRCFailsVal = new System.Windows.Forms.Label();
            this.labelEscCharFails = new System.Windows.Forms.Label();
            this.labelCRCFails = new System.Windows.Forms.Label();
            this.checkBoxLogging = new System.Windows.Forms.CheckBox();
            this.labelGyroXVal = new System.Windows.Forms.Label();
            this.labelGyroYVal = new System.Windows.Forms.Label();
            this.labelGyroZVal = new System.Windows.Forms.Label();
            this.labelAccXVal = new System.Windows.Forms.Label();
            this.labelAccYVal = new System.Windows.Forms.Label();
            this.labelAccZVal = new System.Windows.Forms.Label();
            this.labelt1Val = new System.Windows.Forms.Label();
            this.labelt2Val = new System.Windows.Forms.Label();
            this.labelt3Val = new System.Windows.Forms.Label();
            this.labelIMUTempVal = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label26 = new System.Windows.Forms.Label();
            this.label25 = new System.Windows.Forms.Label();
            this.label24 = new System.Windows.Forms.Label();
            this.label23 = new System.Windows.Forms.Label();
            this.label22 = new System.Windows.Forms.Label();
            this.label21 = new System.Windows.Forms.Label();
            this.label20 = new System.Windows.Forms.Label();
            this.label19 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.ADCtempLABEL1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.labelShaftSpeed = new System.Windows.Forms.Label();
            this.label31 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.ADCtempLABEL2 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.labelIMUTempVal2 = new System.Windows.Forms.Label();
            this.labelAccZVal2 = new System.Windows.Forms.Label();
            this.labelAccYVal2 = new System.Windows.Forms.Label();
            this.labelAccXVal2 = new System.Windows.Forms.Label();
            this.labelShaftRevs = new System.Windows.Forms.Label();
            this.labelPWMVal1 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label28 = new System.Windows.Forms.Label();
            this.label29 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label34 = new System.Windows.Forms.Label();
            this.label35 = new System.Windows.Forms.Label();
            this.label32 = new System.Windows.Forms.Label();
            this.label33 = new System.Windows.Forms.Label();
            this.labelFramesSent = new System.Windows.Forms.Label();
            this.label30 = new System.Windows.Forms.Label();
            this.labelRefreshRate = new System.Windows.Forms.Label();
            this.labelBaudRate = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label27 = new System.Windows.Forms.Label();
            this.label36 = new System.Windows.Forms.Label();
            this.label37 = new System.Windows.Forms.Label();
            this.labelMotorCurrent = new System.Windows.Forms.Label();
            this.groupBoxWarnings.SuspendLayout();
            this.groupBoxCRC.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // serialComboBox
            // 
            this.serialComboBox.FormattingEnabled = true;
            this.serialComboBox.Items.AddRange(new object[] {
            "COM1",
            "COM2",
            "COM3",
            "COM4",
            "COM5",
            "COM6",
            "COM7",
            "COM8",
            "COM9",
            "COM10",
            "COM11",
            "COM12",
            "COM13",
            "COM14",
            "COM15",
            "COM16"});
            this.serialComboBox.Location = new System.Drawing.Point(15, 279);
            this.serialComboBox.MaxDropDownItems = 16;
            this.serialComboBox.Name = "serialComboBox";
            this.serialComboBox.Size = new System.Drawing.Size(129, 21);
            this.serialComboBox.TabIndex = 0;
            // 
            // labelSerialPort
            // 
            this.labelSerialPort.AutoSize = true;
            this.labelSerialPort.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelSerialPort.Location = new System.Drawing.Point(33, 254);
            this.labelSerialPort.Name = "labelSerialPort";
            this.labelSerialPort.Size = new System.Drawing.Size(88, 19);
            this.labelSerialPort.TabIndex = 1;
            this.labelSerialPort.Text = "Serial Port";
            // 
            // openButton
            // 
            this.openButton.Font = new System.Drawing.Font("Arial", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.openButton.Location = new System.Drawing.Point(15, 307);
            this.openButton.Name = "openButton";
            this.openButton.Size = new System.Drawing.Size(129, 39);
            this.openButton.TabIndex = 2;
            this.openButton.Text = "Open Port";
            this.openButton.UseVisualStyleBackColor = true;
            this.openButton.Click += new System.EventHandler(this.openButton_Click);
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.PortName = "COM3";
            this.serialPort1.ReadBufferSize = 8192;
            // 
            // textBoxDebug
            // 
            this.textBoxDebug.Location = new System.Drawing.Point(10, 403);
            this.textBoxDebug.Multiline = true;
            this.textBoxDebug.Name = "textBoxDebug";
            this.textBoxDebug.ReadOnly = true;
            this.textBoxDebug.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxDebug.Size = new System.Drawing.Size(308, 104);
            this.textBoxDebug.TabIndex = 7;
            // 
            // labelDebug
            // 
            this.labelDebug.AutoSize = true;
            this.labelDebug.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelDebug.Location = new System.Drawing.Point(11, 381);
            this.labelDebug.Name = "labelDebug";
            this.labelDebug.Size = new System.Drawing.Size(60, 19);
            this.labelDebug.TabIndex = 13;
            this.labelDebug.Text = "Debug";
            // 
            // buttonClearDebug
            // 
            this.buttonClearDebug.Location = new System.Drawing.Point(324, 482);
            this.buttonClearDebug.Name = "buttonClearDebug";
            this.buttonClearDebug.Size = new System.Drawing.Size(42, 22);
            this.buttonClearDebug.TabIndex = 21;
            this.buttonClearDebug.Text = "Clear";
            this.buttonClearDebug.UseVisualStyleBackColor = true;
            this.buttonClearDebug.Click += new System.EventHandler(this.buttonClearDebug_Click);
            // 
            // textBoxWarnings
            // 
            this.textBoxWarnings.Location = new System.Drawing.Point(0, 14);
            this.textBoxWarnings.Multiline = true;
            this.textBoxWarnings.Name = "textBoxWarnings";
            this.textBoxWarnings.ReadOnly = true;
            this.textBoxWarnings.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxWarnings.Size = new System.Drawing.Size(403, 49);
            this.textBoxWarnings.TabIndex = 32;
            // 
            // groupBoxWarnings
            // 
            this.groupBoxWarnings.Controls.Add(this.textBoxWarnings);
            this.groupBoxWarnings.Location = new System.Drawing.Point(344, 367);
            this.groupBoxWarnings.Name = "groupBoxWarnings";
            this.groupBoxWarnings.Size = new System.Drawing.Size(403, 66);
            this.groupBoxWarnings.TabIndex = 33;
            this.groupBoxWarnings.TabStop = false;
            this.groupBoxWarnings.Text = "Warnings/Errors";
            // 
            // groupBoxCRC
            // 
            this.groupBoxCRC.Controls.Add(this.buttonResetCounters);
            this.groupBoxCRC.Controls.Add(this.labelEscCharFailsVal);
            this.groupBoxCRC.Controls.Add(this.labelCRCFailsVal);
            this.groupBoxCRC.Controls.Add(this.labelEscCharFails);
            this.groupBoxCRC.Controls.Add(this.labelCRCFails);
            this.groupBoxCRC.Location = new System.Drawing.Point(209, 254);
            this.groupBoxCRC.Name = "groupBoxCRC";
            this.groupBoxCRC.Size = new System.Drawing.Size(109, 117);
            this.groupBoxCRC.TabIndex = 36;
            this.groupBoxCRC.TabStop = false;
            this.groupBoxCRC.Text = "CRC Information";
            // 
            // buttonResetCounters
            // 
            this.buttonResetCounters.Location = new System.Drawing.Point(34, 74);
            this.buttonResetCounters.Name = "buttonResetCounters";
            this.buttonResetCounters.Size = new System.Drawing.Size(55, 35);
            this.buttonResetCounters.TabIndex = 39;
            this.buttonResetCounters.Text = "Reset";
            this.buttonResetCounters.UseVisualStyleBackColor = true;
            this.buttonResetCounters.Click += new System.EventHandler(this.buttonResetCounters_Click);
            // 
            // labelEscCharFailsVal
            // 
            this.labelEscCharFailsVal.AutoSize = true;
            this.labelEscCharFailsVal.Location = new System.Drawing.Point(76, 48);
            this.labelEscCharFailsVal.Name = "labelEscCharFailsVal";
            this.labelEscCharFailsVal.Size = new System.Drawing.Size(13, 13);
            this.labelEscCharFailsVal.TabIndex = 108;
            this.labelEscCharFailsVal.Text = "0";
            // 
            // labelCRCFailsVal
            // 
            this.labelCRCFailsVal.AutoSize = true;
            this.labelCRCFailsVal.Location = new System.Drawing.Point(76, 28);
            this.labelCRCFailsVal.Name = "labelCRCFailsVal";
            this.labelCRCFailsVal.Size = new System.Drawing.Size(13, 13);
            this.labelCRCFailsVal.TabIndex = 37;
            this.labelCRCFailsVal.Text = "0";
            // 
            // labelEscCharFails
            // 
            this.labelEscCharFails.AutoSize = true;
            this.labelEscCharFails.Location = new System.Drawing.Point(6, 48);
            this.labelEscCharFails.Name = "labelEscCharFails";
            this.labelEscCharFails.Size = new System.Drawing.Size(52, 13);
            this.labelEscCharFails.TabIndex = 107;
            this.labelEscCharFails.Text = "ESC Fails";
            // 
            // labelCRCFails
            // 
            this.labelCRCFails.AutoSize = true;
            this.labelCRCFails.Location = new System.Drawing.Point(6, 28);
            this.labelCRCFails.Name = "labelCRCFails";
            this.labelCRCFails.Size = new System.Drawing.Size(53, 13);
            this.labelCRCFails.TabIndex = 106;
            this.labelCRCFails.Text = "CRC Fails";
            // 
            // checkBoxLogging
            // 
            this.checkBoxLogging.AutoSize = true;
            this.checkBoxLogging.Location = new System.Drawing.Point(15, 352);
            this.checkBoxLogging.Name = "checkBoxLogging";
            this.checkBoxLogging.Size = new System.Drawing.Size(64, 17);
            this.checkBoxLogging.TabIndex = 37;
            this.checkBoxLogging.Text = "Logging";
            this.checkBoxLogging.UseVisualStyleBackColor = true;
            this.checkBoxLogging.CheckedChanged += new System.EventHandler(this.checkBoxLogging_CheckedChanged);
            // 
            // labelGyroXVal
            // 
            this.labelGyroXVal.AutoSize = true;
            this.labelGyroXVal.Location = new System.Drawing.Point(88, 17);
            this.labelGyroXVal.Name = "labelGyroXVal";
            this.labelGyroXVal.Size = new System.Drawing.Size(13, 13);
            this.labelGyroXVal.TabIndex = 38;
            this.labelGyroXVal.Text = "0";
            // 
            // labelGyroYVal
            // 
            this.labelGyroYVal.AutoSize = true;
            this.labelGyroYVal.Location = new System.Drawing.Point(88, 30);
            this.labelGyroYVal.Name = "labelGyroYVal";
            this.labelGyroYVal.Size = new System.Drawing.Size(13, 13);
            this.labelGyroYVal.TabIndex = 39;
            this.labelGyroYVal.Text = "0";
            // 
            // labelGyroZVal
            // 
            this.labelGyroZVal.AutoSize = true;
            this.labelGyroZVal.Location = new System.Drawing.Point(88, 43);
            this.labelGyroZVal.Name = "labelGyroZVal";
            this.labelGyroZVal.Size = new System.Drawing.Size(13, 13);
            this.labelGyroZVal.TabIndex = 40;
            this.labelGyroZVal.Text = "0";
            // 
            // labelAccXVal
            // 
            this.labelAccXVal.AutoSize = true;
            this.labelAccXVal.Location = new System.Drawing.Point(88, 62);
            this.labelAccXVal.Name = "labelAccXVal";
            this.labelAccXVal.Size = new System.Drawing.Size(13, 13);
            this.labelAccXVal.TabIndex = 41;
            this.labelAccXVal.Text = "0";
            // 
            // labelAccYVal
            // 
            this.labelAccYVal.AutoSize = true;
            this.labelAccYVal.Location = new System.Drawing.Point(88, 75);
            this.labelAccYVal.Name = "labelAccYVal";
            this.labelAccYVal.Size = new System.Drawing.Size(13, 13);
            this.labelAccYVal.TabIndex = 42;
            this.labelAccYVal.Text = "0";
            // 
            // labelAccZVal
            // 
            this.labelAccZVal.AutoSize = true;
            this.labelAccZVal.Location = new System.Drawing.Point(88, 88);
            this.labelAccZVal.Name = "labelAccZVal";
            this.labelAccZVal.Size = new System.Drawing.Size(13, 13);
            this.labelAccZVal.TabIndex = 43;
            this.labelAccZVal.Text = "0";
            // 
            // labelt1Val
            // 
            this.labelt1Val.AutoSize = true;
            this.labelt1Val.Location = new System.Drawing.Point(88, 107);
            this.labelt1Val.Name = "labelt1Val";
            this.labelt1Val.Size = new System.Drawing.Size(13, 13);
            this.labelt1Val.TabIndex = 44;
            this.labelt1Val.Text = "0";
            // 
            // labelt2Val
            // 
            this.labelt2Val.AutoSize = true;
            this.labelt2Val.Location = new System.Drawing.Point(88, 120);
            this.labelt2Val.Name = "labelt2Val";
            this.labelt2Val.Size = new System.Drawing.Size(13, 13);
            this.labelt2Val.TabIndex = 45;
            this.labelt2Val.Text = "0";
            // 
            // labelt3Val
            // 
            this.labelt3Val.AutoSize = true;
            this.labelt3Val.Location = new System.Drawing.Point(88, 133);
            this.labelt3Val.Name = "labelt3Val";
            this.labelt3Val.Size = new System.Drawing.Size(13, 13);
            this.labelt3Val.TabIndex = 46;
            this.labelt3Val.Text = "0";
            // 
            // labelIMUTempVal
            // 
            this.labelIMUTempVal.AutoSize = true;
            this.labelIMUTempVal.Location = new System.Drawing.Point(88, 152);
            this.labelIMUTempVal.Name = "labelIMUTempVal";
            this.labelIMUTempVal.Size = new System.Drawing.Size(13, 13);
            this.labelIMUTempVal.TabIndex = 47;
            this.labelIMUTempVal.Text = "0";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(36, 13);
            this.label1.TabIndex = 48;
            this.label1.Text = "GyroX";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(11, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(33, 13);
            this.label2.TabIndex = 49;
            this.label2.Text = "AccX";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(11, 107);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(39, 13);
            this.label3.TabIndex = 50;
            this.label3.Text = "Angles";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(11, 152);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 13);
            this.label4.TabIndex = 51;
            this.label4.Text = "IMU temp";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.label26);
            this.panel1.Controls.Add(this.label25);
            this.panel1.Controls.Add(this.label24);
            this.panel1.Controls.Add(this.label23);
            this.panel1.Controls.Add(this.label22);
            this.panel1.Controls.Add(this.label21);
            this.panel1.Controls.Add(this.label20);
            this.panel1.Controls.Add(this.label19);
            this.panel1.Controls.Add(this.label18);
            this.panel1.Controls.Add(this.label17);
            this.panel1.Controls.Add(this.label16);
            this.panel1.Controls.Add(this.label14);
            this.panel1.Controls.Add(this.label13);
            this.panel1.Controls.Add(this.label12);
            this.panel1.Controls.Add(this.label11);
            this.panel1.Controls.Add(this.label10);
            this.panel1.Controls.Add(this.ADCtempLABEL1);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.labelIMUTempVal);
            this.panel1.Controls.Add(this.labelt3Val);
            this.panel1.Controls.Add(this.labelt2Val);
            this.panel1.Controls.Add(this.labelt1Val);
            this.panel1.Controls.Add(this.labelAccZVal);
            this.panel1.Controls.Add(this.labelAccYVal);
            this.panel1.Controls.Add(this.labelAccXVal);
            this.panel1.Controls.Add(this.labelGyroZVal);
            this.panel1.Controls.Add(this.labelGyroYVal);
            this.panel1.Controls.Add(this.labelGyroXVal);
            this.panel1.Location = new System.Drawing.Point(344, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(207, 206);
            this.panel1.TabIndex = 52;
            // 
            // label26
            // 
            this.label26.AutoSize = true;
            this.label26.Location = new System.Drawing.Point(160, 165);
            this.label26.Name = "label26";
            this.label26.Size = new System.Drawing.Size(18, 13);
            this.label26.TabIndex = 68;
            this.label26.Text = "°C";
            // 
            // label25
            // 
            this.label25.AutoSize = true;
            this.label25.Location = new System.Drawing.Point(160, 152);
            this.label25.Name = "label25";
            this.label25.Size = new System.Drawing.Size(27, 13);
            this.label25.TabIndex = 67;
            this.label25.Text = "N/A";
            // 
            // label24
            // 
            this.label24.AutoSize = true;
            this.label24.Location = new System.Drawing.Point(160, 43);
            this.label24.Name = "label24";
            this.label24.Size = new System.Drawing.Size(35, 13);
            this.label24.TabIndex = 66;
            this.label24.Text = "deg/s";
            // 
            // label23
            // 
            this.label23.AutoSize = true;
            this.label23.Location = new System.Drawing.Point(160, 30);
            this.label23.Name = "label23";
            this.label23.Size = new System.Drawing.Size(35, 13);
            this.label23.TabIndex = 65;
            this.label23.Text = "deg/s";
            // 
            // label22
            // 
            this.label22.AutoSize = true;
            this.label22.Location = new System.Drawing.Point(160, 17);
            this.label22.Name = "label22";
            this.label22.Size = new System.Drawing.Size(35, 13);
            this.label22.TabIndex = 64;
            this.label22.Text = "deg/s";
            // 
            // label21
            // 
            this.label21.AutoSize = true;
            this.label21.Location = new System.Drawing.Point(160, 133);
            this.label21.Name = "label21";
            this.label21.Size = new System.Drawing.Size(29, 13);
            this.label21.TabIndex = 63;
            this.label21.Text = "units";
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Location = new System.Drawing.Point(160, 120);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(29, 13);
            this.label20.TabIndex = 62;
            this.label20.Text = "units";
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(160, 107);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(29, 13);
            this.label19.TabIndex = 61;
            this.label19.Text = "units";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(160, 88);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(28, 13);
            this.label18.TabIndex = 60;
            this.label18.Text = "m/s²";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(160, 75);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(28, 13);
            this.label17.TabIndex = 59;
            this.label17.Text = "m/s²";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(160, 62);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(28, 13);
            this.label16.TabIndex = 58;
            this.label16.Text = "m/s²";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(11, 165);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(55, 13);
            this.label14.TabIndex = 57;
            this.label14.Text = "ADC temp";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(11, 75);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(33, 13);
            this.label13.TabIndex = 56;
            this.label13.Text = "AccY";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(11, 88);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(33, 13);
            this.label12.TabIndex = 55;
            this.label12.Text = "AccZ";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(11, 43);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(36, 13);
            this.label11.TabIndex = 54;
            this.label11.Text = "GyroZ";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(11, 30);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(36, 13);
            this.label10.TabIndex = 53;
            this.label10.Text = "GyroY";
            // 
            // ADCtempLABEL1
            // 
            this.ADCtempLABEL1.AutoSize = true;
            this.ADCtempLABEL1.Location = new System.Drawing.Point(88, 165);
            this.ADCtempLABEL1.Name = "ADCtempLABEL1";
            this.ADCtempLABEL1.Size = new System.Drawing.Size(13, 13);
            this.ADCtempLABEL1.TabIndex = 52;
            this.ADCtempLABEL1.Text = "0";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.label36);
            this.panel2.Controls.Add(this.label37);
            this.panel2.Controls.Add(this.labelMotorCurrent);
            this.panel2.Controls.Add(this.labelShaftSpeed);
            this.panel2.Controls.Add(this.label31);
            this.panel2.Controls.Add(this.label15);
            this.panel2.Controls.Add(this.ADCtempLABEL2);
            this.panel2.Controls.Add(this.label5);
            this.panel2.Controls.Add(this.label6);
            this.panel2.Controls.Add(this.label7);
            this.panel2.Controls.Add(this.label8);
            this.panel2.Controls.Add(this.labelIMUTempVal2);
            this.panel2.Controls.Add(this.labelAccZVal2);
            this.panel2.Controls.Add(this.labelAccYVal2);
            this.panel2.Controls.Add(this.labelAccXVal2);
            this.panel2.Controls.Add(this.labelShaftRevs);
            this.panel2.Controls.Add(this.labelPWMVal1);
            this.panel2.Location = new System.Drawing.Point(557, 12);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(190, 206);
            this.panel2.TabIndex = 53;
            // 
            // labelShaftSpeed
            // 
            this.labelShaftSpeed.AutoSize = true;
            this.labelShaftSpeed.Location = new System.Drawing.Point(112, 69);
            this.labelShaftSpeed.Name = "labelShaftSpeed";
            this.labelShaftSpeed.Size = new System.Drawing.Size(13, 13);
            this.labelShaftSpeed.TabIndex = 55;
            this.labelShaftSpeed.Text = "0";
            // 
            // label31
            // 
            this.label31.AutoSize = true;
            this.label31.Location = new System.Drawing.Point(14, 69);
            this.label31.Name = "label31";
            this.label31.Size = new System.Drawing.Size(78, 13);
            this.label31.TabIndex = 54;
            this.label31.Text = "Dragline speed";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(161, 17);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(15, 13);
            this.label15.TabIndex = 53;
            this.label15.Text = "%";
            // 
            // ADCtempLABEL2
            // 
            this.ADCtempLABEL2.AutoSize = true;
            this.ADCtempLABEL2.Location = new System.Drawing.Point(112, 147);
            this.ADCtempLABEL2.Name = "ADCtempLABEL2";
            this.ADCtempLABEL2.Size = new System.Drawing.Size(13, 13);
            this.ADCtempLABEL2.TabIndex = 52;
            this.ADCtempLABEL2.Text = "0";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(14, 134);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 13);
            this.label5.TabIndex = 51;
            this.label5.Text = "Extra2";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(14, 95);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(37, 13);
            this.label6.TabIndex = 50;
            this.label6.Text = "Extra1";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(14, 56);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(85, 13);
            this.label7.TabIndex = 49;
            this.label7.Text = "Dragline position";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(14, 17);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(34, 13);
            this.label8.TabIndex = 48;
            this.label8.Text = "PWM";
            // 
            // labelIMUTempVal2
            // 
            this.labelIMUTempVal2.AutoSize = true;
            this.labelIMUTempVal2.Location = new System.Drawing.Point(112, 134);
            this.labelIMUTempVal2.Name = "labelIMUTempVal2";
            this.labelIMUTempVal2.Size = new System.Drawing.Size(13, 13);
            this.labelIMUTempVal2.TabIndex = 47;
            this.labelIMUTempVal2.Text = "0";
            // 
            // labelAccZVal2
            // 
            this.labelAccZVal2.AutoSize = true;
            this.labelAccZVal2.Location = new System.Drawing.Point(112, 121);
            this.labelAccZVal2.Name = "labelAccZVal2";
            this.labelAccZVal2.Size = new System.Drawing.Size(13, 13);
            this.labelAccZVal2.TabIndex = 46;
            this.labelAccZVal2.Text = "0";
            // 
            // labelAccYVal2
            // 
            this.labelAccYVal2.AutoSize = true;
            this.labelAccYVal2.Location = new System.Drawing.Point(112, 108);
            this.labelAccYVal2.Name = "labelAccYVal2";
            this.labelAccYVal2.Size = new System.Drawing.Size(13, 13);
            this.labelAccYVal2.TabIndex = 45;
            this.labelAccYVal2.Text = "0";
            // 
            // labelAccXVal2
            // 
            this.labelAccXVal2.AutoSize = true;
            this.labelAccXVal2.Location = new System.Drawing.Point(112, 95);
            this.labelAccXVal2.Name = "labelAccXVal2";
            this.labelAccXVal2.Size = new System.Drawing.Size(13, 13);
            this.labelAccXVal2.TabIndex = 44;
            this.labelAccXVal2.Text = "0";
            // 
            // labelShaftRevs
            // 
            this.labelShaftRevs.AutoSize = true;
            this.labelShaftRevs.Location = new System.Drawing.Point(112, 56);
            this.labelShaftRevs.Name = "labelShaftRevs";
            this.labelShaftRevs.Size = new System.Drawing.Size(13, 13);
            this.labelShaftRevs.TabIndex = 41;
            this.labelShaftRevs.Text = "0";
            // 
            // labelPWMVal1
            // 
            this.labelPWMVal1.AutoSize = true;
            this.labelPWMVal1.Location = new System.Drawing.Point(112, 17);
            this.labelPWMVal1.Name = "labelPWMVal1";
            this.labelPWMVal1.Size = new System.Drawing.Size(13, 13);
            this.labelPWMVal1.TabIndex = 38;
            this.labelPWMVal1.Text = "0";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(37, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(249, 169);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 56;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox2.Image")));
            this.pictureBox2.Location = new System.Drawing.Point(484, 457);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(263, 50);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox2.TabIndex = 57;
            this.pictureBox2.TabStop = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label28);
            this.groupBox1.Controls.Add(this.label29);
            this.groupBox1.Location = new System.Drawing.Point(10, 187);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(308, 61);
            this.groupBox1.TabIndex = 109;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Instructions";
            // 
            // label28
            // 
            this.label28.AutoSize = true;
            this.label28.Location = new System.Drawing.Point(6, 29);
            this.label28.Name = "label28";
            this.label28.Size = new System.Drawing.Size(285, 13);
            this.label28.TabIndex = 107;
            this.label28.Text = "2. Check \"Logging\", then click \"Close Port\" when finished.";
            // 
            // label29
            // 
            this.label29.AutoSize = true;
            this.label29.Location = new System.Drawing.Point(6, 16);
            this.label29.Name = "label29";
            this.label29.Size = new System.Drawing.Size(190, 13);
            this.label29.TabIndex = 106;
            this.label29.Text = "1. Select serial port, and open the port.";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label34);
            this.groupBox2.Controls.Add(this.label35);
            this.groupBox2.Controls.Add(this.label32);
            this.groupBox2.Controls.Add(this.label33);
            this.groupBox2.Controls.Add(this.labelFramesSent);
            this.groupBox2.Controls.Add(this.label30);
            this.groupBox2.Controls.Add(this.labelRefreshRate);
            this.groupBox2.Controls.Add(this.labelBaudRate);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label27);
            this.groupBox2.Location = new System.Drawing.Point(344, 224);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(403, 91);
            this.groupBox2.TabIndex = 110;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Additional information";
            // 
            // label34
            // 
            this.label34.AutoSize = true;
            this.label34.Location = new System.Drawing.Point(161, 68);
            this.label34.Name = "label34";
            this.label34.Size = new System.Drawing.Size(41, 13);
            this.label34.TabIndex = 115;
            this.label34.Text = "100 Hz";
            // 
            // label35
            // 
            this.label35.AutoSize = true;
            this.label35.Location = new System.Drawing.Point(6, 68);
            this.label35.Name = "label35";
            this.label35.Size = new System.Drawing.Size(116, 13);
            this.label35.TabIndex = 114;
            this.label35.Text = "Control loop frequency:";
            // 
            // label32
            // 
            this.label32.AutoSize = true;
            this.label32.Location = new System.Drawing.Point(161, 55);
            this.label32.Name = "label32";
            this.label32.Size = new System.Drawing.Size(35, 13);
            this.label32.TabIndex = 113;
            this.label32.Text = "20 Hz";
            // 
            // label33
            // 
            this.label33.AutoSize = true;
            this.label33.Location = new System.Drawing.Point(6, 55);
            this.label33.Name = "label33";
            this.label33.Size = new System.Drawing.Size(110, 13);
            this.label33.TabIndex = 112;
            this.label33.Text = "XBee data frequency:";
            // 
            // labelFramesSent
            // 
            this.labelFramesSent.AutoSize = true;
            this.labelFramesSent.Location = new System.Drawing.Point(161, 42);
            this.labelFramesSent.Name = "labelFramesSent";
            this.labelFramesSent.Size = new System.Drawing.Size(13, 13);
            this.labelFramesSent.TabIndex = 111;
            this.labelFramesSent.Text = "0";
            // 
            // label30
            // 
            this.label30.AutoSize = true;
            this.label30.Location = new System.Drawing.Point(6, 42);
            this.label30.Name = "label30";
            this.label30.Size = new System.Drawing.Size(67, 13);
            this.label30.TabIndex = 110;
            this.label30.Text = "Frames sent:";
            // 
            // labelRefreshRate
            // 
            this.labelRefreshRate.AutoSize = true;
            this.labelRefreshRate.Location = new System.Drawing.Point(161, 29);
            this.labelRefreshRate.Name = "labelRefreshRate";
            this.labelRefreshRate.Size = new System.Drawing.Size(13, 13);
            this.labelRefreshRate.TabIndex = 109;
            this.labelRefreshRate.Text = "0";
            // 
            // labelBaudRate
            // 
            this.labelBaudRate.AutoSize = true;
            this.labelBaudRate.Location = new System.Drawing.Point(161, 16);
            this.labelBaudRate.Name = "labelBaudRate";
            this.labelBaudRate.Size = new System.Drawing.Size(13, 13);
            this.labelBaudRate.TabIndex = 108;
            this.labelBaudRate.Text = "0";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(6, 29);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(129, 13);
            this.label9.TabIndex = 107;
            this.label9.Text = "Frames between updates:";
            // 
            // label27
            // 
            this.label27.AutoSize = true;
            this.label27.Location = new System.Drawing.Point(6, 16);
            this.label27.Name = "label27";
            this.label27.Size = new System.Drawing.Size(56, 13);
            this.label27.TabIndex = 106;
            this.label27.Text = "Baud rate:";
            // 
            // label36
            // 
            this.label36.AutoSize = true;
            this.label36.Location = new System.Drawing.Point(161, 30);
            this.label36.Name = "label36";
            this.label36.Size = new System.Drawing.Size(22, 13);
            this.label36.TabIndex = 58;
            this.label36.Text = "mA";
            // 
            // label37
            // 
            this.label37.AutoSize = true;
            this.label37.Location = new System.Drawing.Point(14, 30);
            this.label37.Name = "label37";
            this.label37.Size = new System.Drawing.Size(70, 13);
            this.label37.TabIndex = 57;
            this.label37.Text = "Motor current";
            // 
            // labelMotorCurrent
            // 
            this.labelMotorCurrent.AutoSize = true;
            this.labelMotorCurrent.Location = new System.Drawing.Point(112, 30);
            this.labelMotorCurrent.Name = "labelMotorCurrent";
            this.labelMotorCurrent.Size = new System.Drawing.Size(13, 13);
            this.labelMotorCurrent.TabIndex = 56;
            this.labelMotorCurrent.Text = "0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(759, 516);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.checkBoxLogging);
            this.Controls.Add(this.groupBoxCRC);
            this.Controls.Add(this.groupBoxWarnings);
            this.Controls.Add(this.buttonClearDebug);
            this.Controls.Add(this.labelDebug);
            this.Controls.Add(this.textBoxDebug);
            this.Controls.Add(this.openButton);
            this.Controls.Add(this.labelSerialPort);
            this.Controls.Add(this.serialComboBox);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Spider Data Logger App";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBoxWarnings.ResumeLayout(false);
            this.groupBoxWarnings.PerformLayout();
            this.groupBoxCRC.ResumeLayout(false);
            this.groupBoxCRC.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelSerialPort;
        private System.Windows.Forms.Button openButton;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.TextBox textBoxDebug;
        private System.Windows.Forms.Label labelDebug;
        private System.Windows.Forms.ComboBox serialComboBox;
        private System.Windows.Forms.Button buttonClearDebug;
        private System.Windows.Forms.TextBox textBoxWarnings;
        private System.Windows.Forms.GroupBox groupBoxWarnings;
        private System.Windows.Forms.GroupBox groupBoxCRC;
        private System.Windows.Forms.Label labelEscCharFailsVal;
        private System.Windows.Forms.Label labelCRCFailsVal;
        private System.Windows.Forms.Label labelEscCharFails;
        private System.Windows.Forms.Label labelCRCFails;
        private System.Windows.Forms.Button buttonResetCounters;
        private System.Windows.Forms.CheckBox checkBoxLogging;
        private System.Windows.Forms.Label labelGyroXVal;
        private System.Windows.Forms.Label labelGyroYVal;
        private System.Windows.Forms.Label labelGyroZVal;
        private System.Windows.Forms.Label labelAccXVal;
        private System.Windows.Forms.Label labelAccYVal;
        private System.Windows.Forms.Label labelAccZVal;
        private System.Windows.Forms.Label labelt1Val;
        private System.Windows.Forms.Label labelt2Val;
        private System.Windows.Forms.Label labelt3Val;
        private System.Windows.Forms.Label labelIMUTempVal;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label labelIMUTempVal2;
        private System.Windows.Forms.Label labelAccZVal2;
        private System.Windows.Forms.Label labelAccYVal2;
        private System.Windows.Forms.Label labelAccXVal2;
        private System.Windows.Forms.Label labelShaftRevs;
        private System.Windows.Forms.Label ADCtempLABEL1;
        private System.Windows.Forms.Label ADCtempLABEL2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label labelPWMVal1;
        private System.Windows.Forms.Label label24;
        private System.Windows.Forms.Label label23;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label26;
        private System.Windows.Forms.Label label25;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label28;
        private System.Windows.Forms.Label label29;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label labelBaudRate;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label27;
        private System.Windows.Forms.Label labelRefreshRate;
        private System.Windows.Forms.Label labelFramesSent;
        private System.Windows.Forms.Label label30;
        private System.Windows.Forms.Label labelShaftSpeed;
        private System.Windows.Forms.Label label31;
        private System.Windows.Forms.Label label34;
        private System.Windows.Forms.Label label35;
        private System.Windows.Forms.Label label32;
        private System.Windows.Forms.Label label33;
        private System.Windows.Forms.Label label36;
        private System.Windows.Forms.Label label37;
        private System.Windows.Forms.Label labelMotorCurrent;
    }
}

