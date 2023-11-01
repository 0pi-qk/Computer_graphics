using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using SharpGL;

namespace SharpGL
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        float x = 0, y = 0;
        float x1 = 0, y1 = 0;
        private void openGLControl1_OpenGLDraw(object sender, RenderEventArgs args)
        {
            if (k1 == -1) x1 -= 0.1f;
            if (k2 == -1) x1 += 0.1f;
            if (k3 == -1) y1 += 0.1f;
            if (k4 == -1) y1 -= 0.1f;
            if (k5 == -1)
            {
                x -= 3.0f; y -= 3.0f;
            }
            if (k6 == -1)
            {
                x += 3.0f; y += 3.0f;
            }
            // Создаем экземпляр
            OpenGL gl = this.openGLControl1.OpenGL;
            // Очистка экрана и буфера глубин
            gl.Clear(OpenGL.GL_COLOR_BUFFER_BIT | OpenGL.GL_DEPTH_BUFFER_BIT);
            
            // Пирамида /////////////////////////////
            // Сбрасываем модельно-видовую матрицу
            gl.LoadIdentity();
            // Сдвигаем перо влево от центра и вглубь экрана
            gl.Translate(x1, y1, -5.0f);
            // Вращаем пирамиду вокруг ее оси Y
            gl.Rotate(x, 0.0f, 1.0f, 0.0f);
            gl.Rotate(y, 1.0f, 0.0f, 0.0f);
            // Рисуем треугольники - грани пирамиды
            gl.Begin(OpenGL.GL_TRIANGLES);

            // Front
            gl.Color(1.0f, 0.0f, 0.0f);
            gl.Vertex(0.0f, 1.0f, 0.0f);
            gl.Vertex(-1.0f, -1.0f, 1.0f);
            gl.Vertex(1.0f, -1.0f, 1.0f);
            // Right
            gl.Color(0.0f, 1.0f, 0.0f);
            gl.Vertex(0.0f, 1.0f, 0.0f);
            gl.Vertex(1.0f, -1.0f, -1.0f);
            gl.Vertex(1.0f, -1.0f, 1.0f);
            // Back
            gl.Color(0.0f, 0.0f, 1.0f);
            gl.Vertex(0.0f, 1.0f, 0.0f);
            gl.Vertex(1.0f, -1.0f, -1.0f);
            gl.Vertex(-1.0f, -1.0f, -1.0f);
            // Left
            gl.Color(1.0f, 1.0f, 0.0f);
            gl.Vertex(0.0f, 1.0f, 0.0f);
            gl.Vertex(-1.0f, -1.0f, 1.0f);
            gl.Vertex(-1.0f, -1.0f, -1.0f);
            gl.End();
            gl.Begin(OpenGL.GL_QUADS);
            gl.Color(0.5f, 1.0f, 0.5f);
            gl.Color(1.0f, 0.5f, 0.0f);
            gl.Vertex(1.0f, -1.0f, 1.0f);
            gl.Vertex(-1.0f, -1.0f, 1.0f);
            gl.Vertex(-1.0f, -1.0f, -1.0f);
            gl.Vertex(1.0f, -1.0f, -1.0f);
            gl.End();    
            // Контроль полной отрисовки следующего изображения
            gl.Flush();
        }
        int k1 = 1, k2 = 1, k3 = 1, k4 = 1, k5 = 1, k6 = 1;

        private void button1_Click(object sender, EventArgs e)
        {
            k1 = k1 * (-1);
        }
        private void button2_Click(object sender, EventArgs e)
        {
            k2 = k2 * (-1);
        }
        private void button3_Click(object sender, EventArgs e)
        {
            k3 = k3 * (-1);   
        }
        private void button4_Click(object sender, EventArgs e)
        {
            k4 = k4 * (-1);
        }
        private void button5_Click(object sender, EventArgs e)
        {
            k5 = k5 * (-1);
        }
        private void button6_Click(object sender, EventArgs e)
        {
            k6 = k6 * (-1);
        }
    }
}