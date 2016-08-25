/*
 * Copyright (c) 2014-2015 ARM Limited. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NANOSTACK_RF_PHY_ATMEL_H_
#define NANOSTACK_RF_PHY_ATMEL_H_

#include "NanostackRfPhy.h"
#include "at24mac.h"
#include "PinNames.h"

class RFBits;

class NanostackRfPhyAtmel : public NanostackRfPhy {
public:
    NanostackRfPhyAtmel(PinName spi_mosi, PinName spi_miso,
            PinName spi_sclk, PinName spi_cs,  PinName spi_rst, PinName spi_slp, PinName spi_irq,
            PinName i2c_sda, PinName i2c_scl);
    ~NanostackRfPhyAtmel();
    int8_t rf_register();
    void rf_unregister();
    void rf_read_mac_address(uint8_t *mac);

private:
    AT24Mac _mac;
    uint8_t _mac_addr[8];
    RFBits *_rf;

    const PinName _spi_mosi;
    const PinName _spi_miso;
    const PinName _spi_sclk;
    const PinName _spi_cs;
    const PinName _spi_rst;
    const PinName _spi_slp;
    const PinName _spi_irq;
};

#endif /* NANOSTACK_RF_PHY_ATMEL_H_ */
