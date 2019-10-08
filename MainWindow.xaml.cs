using Microsoft.Win32;
using System.Collections.Generic;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;

namespace Week2Tutorial1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            cmbFontFamily.ItemsSource = Fonts.SystemFontFamilies;
            cmbFontSize.ItemsSource = new List<double>() { 8, 9, 10, 11, 12, 13, 14, 16, 18, 20, 22, 24, 26, 28, 31, 36, 48, 72 };
        }

        private void rtbEditor_SelectionChanged(object sender, RoutedEventArgs e)
        {
            object temp = rtbEditor.Selection.GetPropertyValue(FontWeightProperty);

            if (temp != DependencyProperty.UnsetValue && temp.Equals(FontWeights.Bold))
            {
                btnBold.IsChecked = true;
            }
            else
            {
                btnBold.IsChecked = false;
            }

            temp = rtbEditor.Selection.GetPropertyValue(FontStyleProperty);
            if(temp != DependencyProperty.UnsetValue && temp.Equals(FontStyles.Italic))
            {
                btnItalic.IsChecked = true;
            }
            else
            {
                btnItalic.IsChecked = false;
            }

            temp = rtbEditor.Selection.GetPropertyValue(Inline.TextDecorationsProperty);
            if(temp != DependencyProperty.UnsetValue && temp.Equals(TextDecorations.Underline))
            {
                btnUnderline.IsChecked = true;
            }
            else
            {
                btnUnderline.IsChecked = false;
            }

            temp = rtbEditor.Selection.GetPropertyValue(FontSizeProperty);
            cmbFontSize.Text = temp.ToString();

            temp = rtbEditor.Selection.GetPropertyValue(FontFamilyProperty);
            cmbFontFamily.Text = temp.ToString();
        }

        private void cmbFontFamily_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (cmbFontFamily.SelectedItem != null)
            {
                rtbEditor.Selection.ApplyPropertyValue(FontFamilyProperty, cmbFontFamily.SelectedItem);
            }
        }

        private void cmbFontSize_TextChanged(object sender, TextChangedEventArgs e)
        {
            rtbEditor.Selection.ApplyPropertyValue(FontSizeProperty, cmbFontSize.Text);
        }

        private void Save_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            SaveFileDialog saveDialog = new SaveFileDialog();
            saveDialog.Filter = "Rich Text Format (*.rtf)|*.rtf|All Files (*.*)|*.*";
            if (saveDialog.ShowDialog() == true)
            {
                FileStream fileStream = new FileStream(saveDialog.FileName, FileMode.Open);
                TextRange range = new TextRange(rtbEditor.Document.ContentStart, rtbEditor.Document.ContentEnd);
                range.Load(fileStream, DataFormats.Rtf);
            }
        }

        private void Open_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            OpenFileDialog openDialog = new OpenFileDialog()
            {
                Filter = "Rich Text Format (*.rtf)|*.rtf|All Files (*.*)|*.*"
            };

            if (openDialog.ShowDialog() == true)
            {
                FileStream fileStream = new FileStream(openDialog.FileName, FileMode.Open);
                TextRange range = new TextRange(rtbEditor.Document.ContentStart, rtbEditor.Document.ContentEnd);
                range.Load(fileStream, DataFormats.Rtf);
            }
        }
    }
}
