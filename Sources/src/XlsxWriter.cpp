#include "XlsxWriter.h"
#include <xlsxwriter.h>

void XlsxWriter::write(const std::string& filename, const std::vector<JsonParser::Row>& data) {
    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].cells.size(); ++j) {
            worksheet_write_string(worksheet, i, j, data[i].cells[j].c_str(), NULL);
        }
    }
    workbook_close(workbook);
}
