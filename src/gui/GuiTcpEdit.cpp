/**
 * \author Abdelrazak Younes
 *
 * Copyright (c) 2009 Aaron Turner.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the names of the copyright owners nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "GuiTcpEdit.h"

#include "TcpEdit.h"
#include "ui_TcpEdit.h"


struct GuiTcpEdit::Private
{
    Ui::TcpEdit ui;
    TcpEdit edit;
};


GuiTcpEdit::GuiTcpEdit(QWidget *parent) :
        QDockWidget(parent), d(new GuiTcpEdit::Private)
{
    d->ui.setupUi(this);
}


GuiTcpEdit::~GuiTcpEdit()
{
    delete d;
}


void GuiTcpEdit::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        d->ui.retranslateUi(this);
        break;
    default:
        break;
    }
}


void GuiTcpEdit::setTcpEdit(TcpEdit const & edit)
{
    d->edit = edit;
}


TcpEdit const & GuiTcpEdit::tcpEdit() const
{
    return d->edit;
}


void GuiTcpEdit::on_pushButton_apply_clicked(bool)
{
    d->edit.setSkipBroadcast(d->ui.checkBox_skipBroadcast->isChecked());
    //d->edit.setFixlen(tcpedit_fixlen);
    d->edit.setFixCsum(!d->ui.checkBox_redoChecksums->isChecked());
    d->edit.setEfcs(!d->ui.checkBox_removeEFCS->isChecked());
    //d->edit.setTtlMode(tcpedit_ttl_mode);
    d->edit.setTtlValue(d->ui.lineEdit_ttl->text().toUShort());
    d->edit.setTos(d->ui.lineEdit_tos->text().toUShort());
    d->edit.setSeed(d->ui.lineEdit_ipAddressSeed->text().toInt());
    d->edit.setMtu(d->ui.lineEdit_mtu->text().toInt());
    d->edit.setMaxpacket(d->ui.lineEdit_packetSize->text().toInt());
    d->edit.setCidrmap_s2c(d->ui.lineEdit_primaryCIDR->text());
    d->edit.setCidrmap_c2s(d->ui.lineEdit_primaryCIDR->text());
    d->edit.setSrcIpMap(d->ui.lineEdit_ipAddressSrc->text());
    d->edit.setDstIpMap(d->ui.lineEdit_ipAddressDest->text());
    d->edit.setPortMap(d->ui.lineEdit_port->text());
}


void GuiTcpEdit::on_pushButton_revert_clicked(bool)
{
    // FIXME: TcpEdit parameters to dialog.
}

